// Copyright @bigpel66

#ifndef CIRCLE_04_CPP_MODULE_06_EX02_BASE_HPP_
#define CIRCLE_04_CPP_MODULE_06_EX02_BASE_HPP_

#include <exception>
#include <iostream>
#include <string>

#include "Random.hpp"

class Base {
 public:
  virtual ~Base(void) {}
};

class A : public Base {};

class B : public Base {};

class C : public Base {};

Base* generate(void);
void identify(Base* p);
void identify(const Base& p);

#endif  // CIRCLE_04_CPP_MODULE_06_EX02_BASE_HPP_
