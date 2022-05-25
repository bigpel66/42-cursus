// Copyright @bigpel66

// Header for context of the request from the client
#ifndef CIRCLE_05_WEBSERV_INCLUDES_REQCONTEXT_HPP_
#define CIRCLE_05_WEBSERV_INCLUDES_REQCONTEXT_HPP_

// Standard Library Inclusion
#include <string>

// Class Headers Inclusion
#include "./Logger.hpp"
#include "./Utilizer.hpp"

class ReqContext {
 private:
  ReqContext(void);
  ReqContext(const ReqContext& r);
  ReqContext& operator=(const ReqContext& r);

 public:
  ReqContext(const Options& options,
            const ServContexts& serv_contexts,
            const Client& client);
  ~ReqContext(void);

  bool is_method_acceptable(const std::string& method) const;
  void reset_to_redirected_location(const std::string& location);

  bool get_autoindex(void) const;
  size_t get_client_max_body_size(void) const;
  const std::string& get_uri(void) const;
  const std::string& get_root(void) const;
  const std::string& get_upload(void) const;
  const std::string& get_method(void) const;
  const std::string& get_cgi_bin(void) const;
  const std::string& get_auth(void) const;
  const CGIs& get_cgis(void) const;
  const Indexes& get_indexes(void) const;
  const ErrorPages& get_error_pages(void) const;
  const Methods& get_methods(void) const;

  const Client& get_client(void) const;
  const Headers& get_headers(void) const;
  const std::string& get_header(const std::string& key) const;
  const std::string& get_body(void) const;
  const std::string& get_query_string(void) const;
  const std::string& get_resource(void) const;
  const std::string& get_protocol(void) const;
  const std::string& get_host(void) const;
  uint32_t get_port(void) const;
  std::string get_log(log_level level);
};

#endif  // CIRCLE_05_WEBSERV_INCLUDES_REQCONTEXT_HPP_
