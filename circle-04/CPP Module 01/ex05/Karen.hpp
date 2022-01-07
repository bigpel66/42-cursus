// Copyright @bigpel66

#ifndef CIRCLE_04_CPP_MODULE_01_EX05_KAREN_HPP_
#define CIRCLE_04_CPP_MODULE_01_EX05_KAREN_HPP_

#include <iostream>
#include <string>

class Karen {
 private:
  void debug(void);
  void info(void);
  void warning(void);
  void error(void);

 public:
  void complain(std::string level);

  Karen(void);
  ~Karen(void);
};

#endif  //  CIRCLE_04_CPP_MODULE_01_EX05_KAREN_HPP_
