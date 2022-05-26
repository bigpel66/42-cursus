// Copyright @bigpel66

#include "../includes/Parser.hpp"
#include "../includes/Request.hpp"

Request::Request(void)
  : _protocol("HTTP/1.1"),
    _chunk_size(0),
    _body_offset(0),
    _request_status(on_request_line) {
  gettimeofday(&_header_timer, ft::nil);
}

Request::~Request(void) {}

void Request::remove_current_word_from_data(std::size_t length) {
  _data.erase(0, length);
}

void Request::remove_crlf_from_data(std::size_t crlf_position) {
  _data.erase(0, crlf_position + 2);
}

void Request::remove_query_string_from_target(void) {
  _target.erase(get_question_position_from_target());
}

std::string Request::get_current_word_from_data(void) const {
  return _data.substr(0, get_blank_position_from_data());
}

std::string Request::get_query_string_from_target(void) const {
  return _target.substr(get_question_position_from_target() + 1);
}

std::size_t Request::get_crlf_position_from_data(void) const {
  return _data.find("\r\n");
}

std::size_t Request::get_blank_position_from_data(void) const {
  return _data.find(' ');
}

std::size_t Request::get_colon_position_from_data(void) const {
  return _data.find(':');
}

std::size_t Request::get_question_position_from_target(void) const {
  return _target.find('?');
}

bool Request::is_timeout(void) {
  if (!is_on_complete()) {
    _request_status = on_error;
    return true;
  }
  return false;
}

bool Request::is_header_validated(void) const {
  return _request_status > on_validating_headers;
}

bool Request::is_valid_method(const std::string& method) const {
  return method == "GET" ||
          method == "POST" ||
          method == "HEAD" ||
          method == "PUT" ||
          method == "DELETE";
}

bool Request::is_valid_target(void) const {

}

bool Request::is_valid_pair_on_header(void) const {
  return !Parser::is_npos(get_colon_position_from_data());
}

bool Request::is_valid_host_on_header(void) const {
  return _headers.find("Host") != _headers.end() &&
          !_headers.at("Host").empty() &&
          Parser::is_npos(_headers.at("Host").find('@'));
}

bool Request::is_chunk_transfer(void) const {
  return _headers.find("Transfer-Encoding") != _headers.end() &&
          _headers.at("Transfer-Encoding") == "chunked";
}

bool Request::is_body_transfer(void) const {
  return _headers.find("Content-Length") != _headers.end();
}

bool Request::is_target_begin_with_separator(void) const {
  return _target[0] == '/';
}

bool Request::is_target_length_too_long(void) const {
  return _target.length() >= MAXIMUM_URI_LENGTH;
}

bool Request::is_target_queried(void) const {
  return !Parser::is_npos(get_question_position_from_target());
}

bool Request::is_header_too_long(const std::string& key,
                                const std::string& val) const {
  return key.length() > MAXIMUM_HEADER_KEY_LENGTH ||
          val.length() > MAXIMUM_HEADER_VAL_LENGTH;
}

bool Request::is_data_separatable(void) const{
  return !Parser::is_npos(get_crlf_position_from_data());
}

bool Request::is_host_duplicated(const std::string& key) const {
  return key == "Host" && _headers.count(key);
}

bool Request::is_request_status_completable(int code) const {
  return code == on_finish;
}

bool Request::is_body_ready_to_be_sent(void) const {
  return _body.length() == _content_length;
}

bool Request::is_method_GET(void) const {
  return _method == "GET";
}

bool Request::is_method_POST(void) const {
  return _method == "POST";
}

bool Request::is_method_HEAD(void) const {
  return _method == "HEAD";
}

bool Request::is_method_PUT(void) const {
  return _method == "PUT";
}

bool Request::is_method_DELETE(void) const {
  return _method == "DELETE";
}

bool Request::is_on_request_line(void) const {
  return _request_status == on_request_line;
}

bool Request::is_on_headers(void) const {
  return _request_status == on_headers;
}

bool Request::is_on_validating_headers(void) const {
  return _request_status == on_validating_headers;
}

bool Request::is_on_body(void) const {
  return _request_status == on_body;
}

bool Request::is_on_chunk(void) const {
  return _request_status == on_chunk;
}

bool Request::is_on_complete(void) const {
  return _request_status == on_complete;
}

bool Request::is_on_error(void) const {
  return _request_status == on_error;
}

bool Request::is_on_chunk_size(void) const {
  return _chunk_status == on_chunk_size;
}

bool Request::is_on_chunk_body(void) const {
  return _chunk_status == on_chunk_body;
}

bool Request::is_chunk_size_empty(void) const {
  return _chunk_size == 0;
}

time_t Request::get_header_time(void) const {
  return _header_timer.tv_sec;
}

time_t Request::get_body_time(void) const {
  return _body_timer.tv_sec;
}

int Request::parse_request_line(void) {
  if (!is_data_separatable()) {
    return on_continuous;
  }
  _method = get_current_word_from_data();
  if (!is_valid_method(_method)) {
    return 501;
  }
  remove_current_word_from_data(_method.length() + 1);
  if (get_blank_position_from_data() == 0) {
    return 400;
  }
  _target = get_current_word_from_data();
  if (!is_target_begin_with_separator()) {
    return 400;
  }
  if (!is_valid_target()) {
    return 403;
  }
  if (is_target_length_too_long()) {
    return 414;
  }
  remove_current_word_from_data(_target.length() + 1);
  if (get_blank_position_from_data() == 0) {
    return 400;
  }
  if (is_target_queried()) {
    _query_string = get_query_string_from_target();
    remove_query_string_from_target();
  }
  std::size_t crlf_position = get_crlf_position_from_data();
  std::string protocol = _data.substr(0, crlf_position);
  if (_protocol != protocol) {
    return 505;
  }
  remove_crlf_from_data(crlf_position);
  _request_status = on_headers;
  return on_continuous;
}

int Request::parse_headers(void) {
  while (is_data_separatable()) {
    std::size_t crlf_position = get_crlf_position_from_data();
    if (crlf_position == 0) {
      remove_crlf_from_data(crlf_position);
      _request_status = on_validating_headers;
      break;
    }
    if (!is_valid_pair_on_header()) {
      return 400;
    }
    std::size_t colon_position = get_colon_position_from_data();
    if (colon_position == 0 || _data[colon_position - 1] == ' ') {
      return 400;
    }
    std::string key = _data.substr(0, colon_position);
    std::string val = _data.substr(colon_position + 1,
                                  crlf_position - colon_position  - 1);
    if (is_host_duplicated(key)) {
      return 400;
    }
    if (is_header_too_long(key, val)) {
      return 400;
    }
    _headers[key] = Parser::trim_whitespace(&val);
    if (_headers[key].empty()) {
      _headers.erase(key);
    }
    remove_crlf_from_data(crlf_position);
  }
  return on_continuous;
}

int Request::validate_headers(void) {
  if (!is_valid_host_on_header()) {
    return 400;
  }
  if (is_chunk_transfer()) {
    _request_status = on_chunk;
    _chunk_status = on_chunk_size;
  } else if (is_body_transfer()) {
    if (!Parser::is_only_digit(_headers.at("Content-Length"))) {
      return 400;
    }
    _content_length = std::strtod(_headers.at("Content-Length").c_str(), ft::nil);
    _request_status = on_body;
  } else {
    return on_finish;
  }
  if (is_method_GET()) {
    return on_finish;
  }
  return on_continuous;
}

int Request::parse_body(void) {
  if (_data.length() >= _content_length) {
    _body.insert(_body_offset, _data, 0, _content_length);
    _body_offset += _data.length();
    _data.clear();
    if (is_body_ready_to_be_sent()) {
      return on_finish;
    }
    return 400;
  }
  return on_continuous;
}

int Request::validate_chunk_trailer(void) {
  // TODO (@bigpel66)
  return 0;
}

int Request::parse_chunk(void) {
  while (is_data_separatable()) {
    std::size_t crlf_position = get_crlf_position_from_data();
    if (is_on_chunk_size) {
      case_on_chunk_size(crlf_position);
    } else if (is_on_chunk_body) {
      if (is_chunk_size_empty()) {
        if (!_data.empty()) {
          return validate_chunk_trailer();
        }
        return on_finish;
      }
      case_on_chunk_body(crlf_position);
    } else {
      return 501;
    }
  }
  return on_continuous;
}

void Request::check_error_and_set_request_status(int code) {
  if (code > 1) {
    _request_status = on_error;
  }
}

void Request::case_on_request_line(int *code) {
  if (is_on_request_line()) {
    *code = parse_request_line();
    check_error_and_set_request_status(*code);
  }
}

void Request::case_on_headers(int *code) {
  if (is_on_headers()) {
    *code = parse_headers();
    check_error_and_set_request_status(*code);
  }
}

void Request::case_on_validating_headers(int *code) {
  if (is_on_validating_headers()) {
    *code = validate_headers();
    check_error_and_set_request_status(*code);
  }
}

void Request::case_on_body(int *code) {
  if (is_on_body()) {
    *code = parse_body();
    check_error_and_set_request_status(*code);
  }
}

void Request::case_on_chunk_size(std::size_t crlf_position) {
  _chunk_size = ft::length_on_hex(_data.substr(0, crlf_position));
  remove_crlf_from_data(crlf_position);
  _chunk_status = on_chunk_body;
}

void Request::case_on_chunk_body(std::size_t crlf_position) {
  _body += _data.substr(0, crlf_position);
  _chunk_size = 0;
  remove_crlf_from_data(crlf_position);
  _chunk_status = on_chunk_size;
}

void Request::case_on_chunk(int *code) {
  if (is_on_chunk()) {
    *code = parse_chunk();
    check_error_and_set_request_status(*code);
  }
}

int Request::parse(const std::string& data) {
  int code = on_continuous;
  gettimeofday(&_body_timer, ft::nil);
  _data += data;
  case_on_request_line(&code);
  case_on_headers(&code);
  case_on_validating_headers(&code);
  case_on_body(&code);
  case_on_chunk(&code);
  if (is_request_status_completable(code)) {
    _request_status = on_complete;
  }
  return code;
}
