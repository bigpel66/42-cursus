// Copyright @bigpel66

#ifndef CIRCLE_04_CPP_MODULE_01_EX06_KAREN_HPP_
#define CIRCLE_04_CPP_MODULE_01_EX06_KAREN_HPP_

#include <iostream>
#include <string>

class Karen {
 private:
  void censored(void);
  void debug(void);
  void info(void);
  void warning(void);
  void error(void);

 public:
  void complain(std::string level);

  Karen(void);
  ~Karen(void);
};

#endif  // CIRCLE_04_CPP_MODULE_01_EX06_KAREN_HPP_
