// Copyright @bigpel66

#ifndef CIRCLE_04_CPP_MODULE_06_EX00_CONVERT_HPP_
#define CIRCLE_04_CPP_MODULE_06_EX00_CONVERT_HPP_

#include <cmath>
#include <cstdlib>
#include <limits>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <stdexcept>
#include <string>

#define C_ND              "Non displayable"
#define C_NP              "impossible"

class Convert {
 private:
  bool _e;
  const std::string _input;
  const double _value;

  Convert(void);

 public:
  char toChar(void) const;
  int toInt(void) const;
  float toFloat(void) const;
  double toDouble(void) const;

  bool getError(void) const;
  const double& getValue(void) const;
  const std::string& getInput(void) const;

  Convert& operator=(const Convert& c);
  explicit Convert(const std::string& input);
  Convert(const Convert& c);
  ~Convert(void);
};

std::ostream& operator<<(std::ostream& o, const Convert& c);

#endif  // CIRCLE_04_CPP_MODULE_06_EX00_CONVERT_HPP_
