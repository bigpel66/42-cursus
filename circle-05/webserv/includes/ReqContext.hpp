// Copyright @bigpel66

// Header for context of the request from the client
#ifndef CIRCLE_05_WEBSERV_INCLUDES_REQCONTEXT_HPP_
#define CIRCLE_05_WEBSERV_INCLUDES_REQCONTEXT_HPP_

// Standard Library Inclusion
#include <string>

// Class Headers Inclusion
#include "./Logger.hpp"
#include "./Request.hpp"
#include "./Utilizer.hpp"

class ReqContext {
 private:
  std::string _resource;
  const Request& _request;
  const Listen& _listen;
  const Client& _client;
  const ServContexts& _serv_contexts;

  ServContext *_serv_context;
  ServContext *_location;

  ReqContext(void);
  ReqContext(const ReqContext& r);
  ReqContext& operator=(const ReqContext& r);

  Location *get_location_from_regex(Locations *regex_locations,
                                    const std::string& resource);

  bool is_regex_decision_required(Location *location) const;
  bool is_target_exactly_matched(Location *location) const;
  bool is_target_prefix_matched(Location *location) const;
  bool is_location_candidate(Location *location) const;
  bool is_location_found_answer(void) const;
  bool is_nested_locations_exist(void) const;
  bool is_listen_matched(const Listen& listen) const;

  void case_prefix_matched(Location *location);
  void check_nested_locations(Locations *regex_locations);
  void check_regex_match_and_allocate(Locations *regex_locations);
  void find_location_answer(void);
  void iterate_listens_in_serv_context(ServContext *serv_context,
                                      ServContexts *matched);
  void iterate_serv_contexts_in_matched(const ServContexts& matched);
  void iterate_locations_in_serv_context(void);
  void set_resource_from_target(void);
  void set_serv_context_on_request(void);
  void set_location_on_request(void);
  void init(void);

 public:
  ReqContext(const Request& request,
            const Client& client,
            const ServContexts& serv_contexts);
  ~ReqContext(void);

  bool is_method_acceptable(const std::string& method) const;
  void reset_to_redirected_location(const std::string& target);

  bool get_autoindex(void) const;
  std::size_t get_client_max_body_size(void) const;
  const std::string& get_uri(void) const;
  const std::string& get_root(void) const;
  const std::string& get_upload(void) const;
  const std::string& get_cgi_bin(void) const;
  const std::string& get_auth(void) const;
  const CGIs& get_cgis(void) const;
  const Indexes& get_indexes(void) const;
  ErrorPages& get_error_pages(void) const;
  const Methods& get_methods(void) const;

  const Client& get_client(void) const;
  const Headers& get_headers(void) const;
  const std::string& get_header(const std::string& key) const;
  std::string& get_method(void);
  const std::string& get_body(void) const;
  const std::string& get_query_string(void) const;
  const std::string& get_resource(void) const;
  const std::string& get_target(void) const;
  const std::string& get_protocol(void) const;
  const std::string& get_host(void) const;
  std::uint32_t get_port(void) const;
  std::string get_log(void);
};

#endif  // CIRCLE_05_WEBSERV_INCLUDES_REQCONTEXT_HPP_
