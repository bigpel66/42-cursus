// Copyright @bigpel66

#include "../includes/ServContext.hpp"
#include "../includes/ReqContext.hpp"
#include "../includes/Client.hpp"
#include "../includes/Parser.hpp"

ReqContext::ReqContext(const Request& request,
          const Client& client,
          const ServContexts& serv_contexts)
  : _resource(request.get_target()),
    _request(request),
    _listen(client.get_listen()),
    _client(client),
    _serv_contexts(serv_contexts),
    _serv_context(ft::nil),
    _location(ft::nil) {
  init();
}

ReqContext::~ReqContext(void) {}

Location *ReqContext::get_location_from_regex(Locations *regex_locations,
                                              const std::string& resource) {
  regex_t regex;
  for (Locations::const_iterator it = regex_locations->begin()
      ; it != regex_locations->end()
      ; it++) {
    int regex_option = REG_NOSUB | REG_EXTENDED;
    if ((*it)->_modifier == case_insensitive_match) {
      regex_option |= REG_ICASE;
    }
    int error = regcomp(&regex, resource.c_str(), regex_option);
    if (!error) {
      bool is_missed = regexec(&regex, resource.c_str(), 0, ft::nil, 0);
      regfree(&regex);
      if (!is_missed) {
        return *it;
      }
    }
  }
  return ft::nil;
}

void ReqContext::reset_to_redirected_location(const std::string& target) {
  _resource = target;
  set_location_on_request();
}

bool ReqContext::is_method_acceptable(const std::string& method) const {
  const Methods& methods = _location->_methods;
  if (methods.empty()) {
    return true;
  }
  if (std::find(methods.begin(), methods.end(), method) != methods.end()) {
    return true;
  }
  return false;
}

bool ReqContext::is_regex_decision_required(Location *location) const {
  return location->_modifier == case_sensitive_match ||
          location->_modifier == case_insensitive_match;
}

bool ReqContext::is_target_exactly_matched(Location *location) const {
  return location->_modifier == exact_match &&
          location->_match_uri == _resource;
}

bool ReqContext::is_target_prefix_matched(Location *location) const {
  return _resource.find(location->_match_uri) == 0;
}

bool ReqContext::is_location_candidate(Location *location) const {
  return !_location ||
        (_location &&
        _location->_match_uri.length() < location->_match_uri.length());
}

bool ReqContext::is_location_found_answer(void) const {
  return _location && _location->_modifier == longest_match;
}

bool ReqContext::is_nested_locations_exist(void) const {
  return _location && !_location->_locations.empty();
}

bool ReqContext::is_listen_matched(const Listen& listen) const {
  return (listen.get_ip() == _listen.get_ip() ||
          listen.get_ip() == "0.0.0.0") &&
          listen.get_port() == _listen.get_port();
}

void ReqContext::case_prefix_matched(Location *location) {
  if (is_location_candidate(location)) {
    _location = location;
  }
}

void ReqContext::check_nested_locations(Locations *regex_locations) {
  if (is_nested_locations_exist()) {
    for (Locations::const_iterator it = _location->_locations.begin()
        ; it != _location->_locations.end()
        ; it++) {
      if (is_regex_decision_required(*it)) {
        regex_locations->push_back(*it);
      }
    }
  }
}

void ReqContext::check_regex_match_and_allocate(Locations *regex_locations) {
  Location *location = get_location_from_regex(regex_locations, _resource);
  if (location) {
    _location = location;
  }
}

void ReqContext::iterate_listens_in_serv_context(ServContext *serv_context,
                                                ServContexts *matched) {
  for (Listens::const_iterator it = serv_context->get_listens().begin()
      ; it != serv_context->get_listens().end()
      ; it++) {
    if (is_listen_matched(*it)) {
      matched->push_back(serv_context);
      break;
    }
  }
}

void ReqContext::iterate_serv_contexts_in_matched(const ServContexts& matched) {
  std::string addr = _request._headers
                          .at("Host")
                          .substr(0, _request._headers.at("Host").find(':'));
  for (ServContexts::const_iterator fit = matched.begin()
      ; fit != matched.end()
      ; fit++) {
    const ServerNames& names = (*fit)->get_server_names();
    for (ServerNames::const_iterator sit = names.begin()
        ; sit != names.end()
        ; sit++) {
      if (*sit == addr) {
        _serv_context = *fit;
        return;
      }
    }
  }
  _serv_context = matched.front();
}

void ReqContext::iterate_locations_in_serv_context(void) {
  Locations regex_locations;
  for (Locations::const_iterator it = _serv_context->_locations.begin()
      ; it != _serv_context->_locations.end()
      ; it++) {
    if (is_regex_decision_required(*it)) {
      regex_locations.push_back(*it);
    } else if (is_target_exactly_matched(*it)) {
      _location = *it;
      return;
    } else if (is_target_prefix_matched(*it)) {
      case_prefix_matched(*it);
    }
  }
  if (!is_location_found_answer()) {
    check_nested_locations(&regex_locations);
    check_regex_match_and_allocate(&regex_locations);
  }
}

void ReqContext::set_resource_from_target(void) {
  _resource.erase(0, _location->_match_uri.length());
}

void ReqContext::set_serv_context_on_request(void) {
  ServContexts matched;
  for (ServContexts::const_iterator it = _serv_contexts.begin()
      ; it != _serv_contexts.end()
      ; it++) {
    iterate_listens_in_serv_context(*it, &matched);
  }
  if (matched.size() == 1) {
    _serv_context = matched.front();
    return;
  }
  iterate_serv_contexts_in_matched(matched);
}

void ReqContext::set_location_on_request(void) {
  if (_request.is_header_validated()) {
    iterate_locations_in_serv_context();
  }
  if (!_location) {
    _location = _serv_context;
  } else {
    set_resource_from_target();
  }
}

void ReqContext::init(void) {
  set_serv_context_on_request();
  set_location_on_request();
}

bool ReqContext::get_autoindex(void) const {
  return _location->_is_auto_index_on;
}

std::size_t ReqContext::get_client_max_body_size(void) const {
  return _location->_client_max_body_size;
}

const std::string& ReqContext::get_uri(void) const {
  return _location->_match_uri;
}

const std::string& ReqContext::get_root(void) const {
  return _location->_root;
}

const std::string& ReqContext::get_upload(void) const {
  return _location->_upload;
}

const std::string& ReqContext::get_cgi_bin(void) const {
  return _location->_cgi_bin;
}

const std::string& ReqContext::get_auth(void) const {
  return _location->_credentials;
}

const CGIs& ReqContext::get_cgis(void) const {
  return _location->_cgis;
}

const Indexes& ReqContext::get_indexes(void) const {
  return _location->_indexes;
}

const ErrorPages& ReqContext::get_error_pages(void) const {
  return _location->_error_pages;
}

const Methods& ReqContext::get_methods(void) const {
  return _location->_methods;
}

const Client& ReqContext::get_client(void) const {
  return _client;
}

const Headers& ReqContext::get_headers(void) const {
  return _request._headers;
}

const std::string& ReqContext::get_header(const std::string& key) const {
  return _request._headers.at(key);
}

const std::string& ReqContext::get_method(void) const {
  return _request._method;
}

const std::string& ReqContext::get_body(void) const {
  return _request._body;
}

const std::string& ReqContext::get_query_string(void) const {
  return _request._query_string;
}

const std::string& ReqContext::get_resource(void) const {
  return _resource;
}

const std::string& ReqContext::get_target(void) const {
  return _request._target;
}

const std::string& ReqContext::get_protocol(void) const {
  return _request._protocol;
}

const std::string& ReqContext::get_host(void) const {
  return _listen.get_ip();
}

std::uint32_t ReqContext::get_port(void) const {
  return _listen.get_port();
}

std::string ReqContext::get_log(log_level level) {
  std::ostringstream stream;
  stream << "\n\t\t[    server]\t" << std::to_string(_serv_context->_id)
    << "\n\t\t[    method]\t" << get_method()
    << "\n\t\t[  location]\t" << get_uri()
    << "\n\t\t[  resource]\t" << get_resource();
  return stream.str();
}
