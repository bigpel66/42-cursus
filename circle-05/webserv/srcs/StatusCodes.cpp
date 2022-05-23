// Copyright @bigpel66

#include "../includes/StatusCodes.hpp"

StatusCodes::StatusCodes(void) {
  _mapper[-1] = "Invalid Status Code";

  // Informational 1xx
  _mapper[100] = "Continue";
  _mapper[101] = "Switching Protocols";

  // Successful 2xx
  _mapper[200] = "OK";
  _mapper[201] = "Created";
  _mapper[202] = "Accepted";
  _mapper[203] = "Non-Authoritative Information";
  _mapper[204] = "No Content";
  _mapper[205] = "Reset Content";
  _mapper[206] = "Partial Content";

  // Redirection 3xx
  _mapper[300] = "Multiple Choices";
  _mapper[301] = "Moved Permanently";
  _mapper[302] = "Found";
  _mapper[303] = "See Other";
  _mapper[304] = "Not Modified";
  _mapper[305] = "Use Proxy";
  _mapper[307] = "Temporary Redirect";

  // Client Error 4xx
  _mapper[400] = "Bad Request";
  _mapper[401] = "Unauthorized";
  _mapper[402] = "Payment Required";
  _mapper[403] = "Forbidden";
  _mapper[404] = "Not Found";
  _mapper[405] = "Method Not Allowed";
  _mapper[406] = "Not Acceptable";
  _mapper[407] = "Proxy Authentication Required";
  _mapper[408] = "Request Timeout";
  _mapper[409] = "Conflict";
  _mapper[410] = "Gone";
  _mapper[411] = "Length Required";
  _mapper[412] = "Precondition Failed";
  _mapper[413] = "Payload Too Large";
  _mapper[414] = "URI Too Long";
  _mapper[415] = "Unsupported Media Type";
  _mapper[416] = "Range Not Satisfiable";
  _mapper[417] = "Expectation Failed";
  _mapper[426] = "Upgrade Required";

  // Server Error 5xx
  _mapper[500] = "Internal Server Error";
  _mapper[501] = "Not Implemented";
  _mapper[502] = "Bad Gateway";
  _mapper[503] = "Service Unavailable";
  _mapper[504] = "Gateway Timeout";
  _mapper[505] = "HTTP Version Not Supported";
}

StatusCodes::~StatusCodes(void) {}

const std::string& StatusCodes::operator[](int code) {
  if (_mapper.count(code)) {
    return _mapper[code];
  }
  return _mapper[-1];
}
