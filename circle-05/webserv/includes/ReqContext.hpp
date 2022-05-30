// Copyright @bigpel66

// Header for context of the request from the client
#ifndef CIRCLE_05_WEBSERV_INCLUDES_REQCONTEXT_HPP_
#define CIRCLE_05_WEBSERV_INCLUDES_REQCONTEXT_HPP_

// Standard Library Inclusion
#include <string>

// Class Headers Inclusion
#include "./Client.hpp"
#include "./Logger.hpp"
#include "./Request.hpp"
#include "./Utilizer.hpp"
#include "./ServContext.hpp"

class ReqContext {
 private:
  std::string _resource;
  Request &_request;
  Listen &_listen;
  Client &_client;
  ServContexts &_serv_contexts;

  ServContext *_serv_context;
  ServContext *_location;

  bool is_listen_matched(const Listen& listen) const;
  bool is_regex_decision_required(const Location& location) const;
  bool is_target_exactly_matched(const Location& location) const;
  bool is_target_prefix_matched(const Location& location) const;
  bool is_location_candidate(const Location& location) const;
  bool is_location_found_answer(void) const;
  bool is_nested_locations_exist(void) const;

  void iterate_listens_in_serv_context(ServContext *serv_context, ServContextPtrs *matched);
  void iterate_serv_contexts_in_matched(const ServContextPtrs& matched);
  void set_serv_context_on_request(void);

  void case_prefix_matched(Location *location);
  void check_nested_locations(LocationPtrs *regex_locations);
  Location *get_location_from_regex(LocationPtrs *regex_locations);
  void check_regex_match_and_allocate(LocationPtrs *regex_locations);
  void iterate_locations_in_serv_context(void);
  void set_resource_from_target(void);
  void set_location_on_request(void);

  ReqContext(void);
  ReqContext(const ReqContext& r);
  ReqContext& operator=(const ReqContext& r);

 public:
  ReqContext(Request *request,
            Client *client,
            ServContexts *serv_contexts);
  ~ReqContext(void);

  bool is_method_acceptable(const std::string& method) const;

  void init(void);
  void reset_to_redirected_location(const std::string& target);

  bool get_autoindex(void) const;
  std::size_t get_client_max_body_size(void) const;
  const std::string& get_uri(void) const;
  const std::string& get_root(void) const;
  const std::string& get_upload(void) const;
  const std::string& get_cgi_bin(void) const;
  const std::string& get_auth(void) const;
  const Indexes& get_indexes(void) const;
  const Methods& get_methods(void) const;
  const Client& get_client(void) const;
  const CGIs& get_cgis(void) const;
  const ErrorPages& get_error_pages(void) const;
  const Headers& get_headers(void) const;
  const std::string& get_cgi(const std::string& key) const;
  const std::string& get_error_page(int code) const;
  const std::string& get_header(const std::string& key) const;
  const std::string& get_method(void) const;
  const std::string& get_body(void) const;
  const std::string& get_query_string(void) const;
  const std::string& get_resource(void) const;
  const std::string& get_target(void) const;
  const std::string& get_protocol(void) const;
  const std::string& get_host(void) const;
  std::uint32_t get_port(void) const;

  void set_method(const std::string& method);
};

#endif  // CIRCLE_05_WEBSERV_INCLUDES_REQCONTEXT_HPP_
