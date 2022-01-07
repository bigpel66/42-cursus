// Copyright @bigpel66

#ifndef CIRCLE_04_CPP_MODULE_01_EX04_REPLACE_HPP_
#define CIRCLE_04_CPP_MODULE_01_EX04_REPLACE_HPP_

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

class Replace {
 private:
  Replace(void);
  ~Replace(void);

  static void _transform(std::string* str,
                        const std::string& s1,
                        const std::string& s2);

 public:
  static void process(const std::string& txt,
                      const std::string& s1,
                      const std::string& s2);
};

#endif  // CIRCLE_04_CPP_MODULE_01_EX04_REPLACE_HPP_
