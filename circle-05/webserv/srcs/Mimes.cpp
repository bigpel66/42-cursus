// Copyright @bigpel66

#include "../includes/Mimes.hpp"

Mimes::Mimes(void) {
  _mapper["default"]
  = "application/octet-stream";

  _mapper[".html"]
  = "text/html";
  _mapper[".htm"]
  = "text/html";
  _mapper[".shtml"]
  = "text/html";
  _mapper[".css"]
  = "text/css";
  _mapper[".xml"]
  = "text/xml";
  _mapper[".gif"]
  = "image/gif";
  _mapper[".jpeg"]
  = "image/jpeg";
  _mapper[".jpg"]
  = "image/jpeg";
  _mapper[".js"]
  = "application/javascript";
  _mapper[".atom"]
  = "application/atom+xml";
  _mapper[".rss"]
  = "application/rss+xml";

  _mapper[".mml"]
  = "text/mathml";
  _mapper[".txt"]
  = "text/plain";
  _mapper[".jad"]
  = "text/vnd.sun.j2me.app-descriptor";
  _mapper[".wml"]
  = "text/vnd.wap.wml";
  _mapper[".htc"]
  = "text/x-component";

  _mapper[".png"]
  = "image/png";
  _mapper[".svg"]
  = "image/svg+xml";
  _mapper[".svgz"]
  = "image/svg+xml";
  _mapper[".tif"]
  = "image/tiff";
  _mapper[".tiff"]
  = "image/tiff";
  _mapper[".wbmp"]
  = "image/vnd.wap.wbmp";
  _mapper[".webp"]
  = "image/webp";
  _mapper[".ico"]
  = "image/x-icon";
  _mapper[".jng"]
  = "image/x-jng";
  _mapper[".bmp"]
  = "image/x-ms-bmp";

  _mapper[".woff"]
  = "font/woff";
  _mapper[".woff2"]
  = "font/woff2";

  _mapper[".jar"]
  = "application/java-archive";
  _mapper[".war"]
  = "application/java-archive";
  _mapper[".ear"]
  = "application/java-archive";
  _mapper[".json"]
  = "application/json";
  _mapper[".hqx"]
  = "application/mac-binhex40";
  _mapper[".doc"]
  = "application/msword";
  _mapper[".pdf"]
  = "application/pdf";
  _mapper[".ps"]
  = "application/postscript";
  _mapper[".eps"]
  = "application/postscript";
  _mapper[".ai"]
  = "application/postscript";
  _mapper[".rtf"]
  = "application/rtf";
  _mapper[".m3u8"]
  = "application/vnd.apple.mpegurl";
  _mapper[".kml"]
  = "application/vnd.google-earth.kml+xml";
  _mapper[".kmz"]
  = "application/vnd.google-earth.kmz";
  _mapper[".xls"]
  = "application/vnd.ms-excel";
  _mapper[".eot"]
  = "application/vnd.ms-fontobject";
  _mapper[".ppt"]
  = "application/vnd.ms-powerpoint";
  _mapper[".odg"]
  = "application/vnd.oasis.opendocument.graphics";
  _mapper[".odp"]
  = "application/vnd.oasis.opendocument.presentation";
  _mapper[".ods"]
  = "application/vnd.oasis.opendocument.spreadsheet";
  _mapper[".odt"]
  = "application/vnd.oasis.opendocument.text";

  _mapper[".pptx"]
  = "application/vnd.openxmlformats-officedocument.presentationml.presentation";
  _mapper[".xlsx"]
  = "application/vnd.openxmlformats-officedocument.spreadsheetml.sheet";
  _mapper[".docx"]
  = "application/vnd.openxmlformats-officedocument.wordprocessingml.document";

  _mapper[".wmlc"]
  = "application/vnd.wap.wmlc";
  _mapper[".7z"]
  = "application/x-7z-compressed";
  _mapper[".cco"]
  = "application/x-cocoa";
  _mapper[".jardiff"]
  = "application/x-java-archive-diff";
  _mapper[".jnlp"]
  = "application/x-java-jnlp-file";
  _mapper[".run"]
  = "application/x-makeself";
  _mapper[".pl"]
  = "application/x-perl";
  _mapper[".pm"]
  = "application/x-perl";
  _mapper[".prc"]
  = "application/x-pilot";
  _mapper[".pdb"]
  = "application/x-pilot";
  _mapper[".rar"]
  = "application/x-rar-compressed";
  _mapper[".rpm"]
  = "application/x-redhat-package-manager";
  _mapper[".sea"]
  = "application/x-sea";
  _mapper[".swf"]
  = "application/x-shockwave-flash";
  _mapper[".sit"]
  = "application/x-stuffit";
  _mapper[".tcl"]
  = "application/x-tcl";
  _mapper[".tk"]
  = "application/x-tcl";
  _mapper[".der"]
  = "application/x-x509-ca-cert";
  _mapper[".pem"]
  = "application/x-x509-ca-cert";
  _mapper[".crt"]
  = "application/x-x509-ca-cert";
  _mapper[".xpi"]
  = "application/x-xpinstall";
  _mapper[".xhtml"]
  = "application/xhtml+xml";
  _mapper[".xspf"]
  = "application/xspf+xml";
  _mapper[".zip"]
  = "application/zip";

  _mapper[".bin"]
  = "application/octet-stream";
  _mapper[".exe"]
  = "application/octet-stream";
  _mapper[".dll"]
  = "application/octet-stream";
  _mapper[".deb"]
  = "application/octet-stream";
  _mapper[".dmg"]
  = "application/octet-stream";
  _mapper[".iso"]
  = "application/octet-stream";
  _mapper[".img"]
  = "application/octet-stream";
  _mapper[".msi"]
  = "application/octet-stream";
  _mapper[".msp"]
  = "application/octet-stream";
  _mapper[".msm"]
  = "application/octet-stream";

  _mapper[".mid"]
  = "audio/midi";
  _mapper[".midi"]
  = "audio/midi";
  _mapper[".kar"]
  = "audio/midi";
  _mapper[".mp3"]
  = "audio/mpeg";
  _mapper[".ogg"]
  = "audio/ogg";
  _mapper[".m4a"]
  = "audio/x-m4a";
  _mapper[".ra"]
  = "audio/x-realaudio";

  _mapper[".3gpp"]
  = "video/3gpp";
  _mapper[".3gp"]
  = "video/3gpp";
  _mapper[".ts"]
  = "video/mp2t";
  _mapper[".mp4"]
  = "video/mp4";
  _mapper[".mpeg"]
  = "video/mpeg";
  _mapper[".mpg"]
  = "video/mpeg";
  _mapper[".mov"]
  = "video/quicktime";
  _mapper[".webm"]
  = "video/webm";
  _mapper[".flv"]
  = "video/x-flv";
  _mapper[".m4v"]
  = "video/x-m4v";
  _mapper[".mng"]
  = "video/x-mng";
  _mapper[".asx"]
  = "video/x-ms-asf";
  _mapper[".asf"]
  = "video/x-ms-asf";
  _mapper[".wmv"]
  = "video/x-ms-wmv";
  _mapper[".avi"]
  = "video/x-msvideo";
}

Mimes::~Mimes(void) {}

const std::string& Mimes::get_content_type(const std::string& extension) {
  if (_mapper.count(extension)) {
    return _mapper[extension];
  }
  return _mapper["default"];
}
