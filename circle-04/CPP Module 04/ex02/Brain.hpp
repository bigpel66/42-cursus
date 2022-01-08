// Copyright @bigpel66

#ifndef CIRCLE_04_CPP_MODULE_04_EX02_BRAIN_HPP_
#define CIRCLE_04_CPP_MODULE_04_EX02_BRAIN_HPP_

#include <iomanip>
#include <iostream>
#include <string>

#include "Random.hpp"

#define W_SIZE            12
#define B_NAME            "Brain"
#define I_SIZE            100
#define I_LENGTH          10

class Brain {
 private:
  std::string _idea[I_SIZE];

 public:
  static std::string  randomString(void);
  void setIdea(const int& i, const std::string& idea);
  std::string getIdea(const int& i) const;

  Brain& operator=(const Brain& b);
  Brain(void);
  Brain(const Brain& b);
  ~Brain();
};

std::ostream& operator<<(std::ostream& o, const Brain& b);

#endif
