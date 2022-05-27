// Copyright @bigpel66

#include "../includes/CGI.hpp"

CGI::CGI(int worker_id, const File& file, ReqContext *req_context)
  : _worker_id(worker_id),
    _envp(ft::nil),
    _file(file),
    _req_context(*req_context) {
  if (_req_context.get_body().empty() && _req_context.get_method() != "POST") {
    _req_body = _file.get_content();
  } else {
    _req_body = _req_context.get_body();
  }
}

CGI::~CGI(void) {
  ft::safe_delete(&(_argv[0]));
  ft::safe_delete(&(_argv[1]));
  ft::safe_delete_all(&_envp);
  _tmp.close();
  _tmp.unlink();
}

void CGI::init(void) {

}

void CGI::set_env(void) {

}

const std::string& CGI::get_body(void) const {
  return _res_body;
}

int CGI::exec(void) {

}

void CGI::parse_headers(Headers *headers) {

}
