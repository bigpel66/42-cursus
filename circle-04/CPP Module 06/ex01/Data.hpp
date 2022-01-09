// Copyright @bigpel66

#ifndef CIRCLE_04_CPP_MODULE_06_EX01_DATA_HPP_
#define CIRCLE_04_CPP_MODULE_06_EX01_DATA_HPP_

#include <cstdint>
#include <string>
#include <iostream>

class Data {
 private:
  std::string _model;
  int _serial;
  double _price;
  float _weight;


 public:
  const std::string& getModel(void) const;
  const int& getSerial(void) const;
  const double& getPrice(void) const;
  const float& getWeight(void) const;

  Data& operator=(const Data& d);
  Data(void);
  Data(const std::string& model, int serial, double price, float weight);
  Data(const Data& d);
  ~Data(void);
};

uintptr_t serialize(Data* ptr);
Data* deserialize(uintptr_t raw);
std::ostream& operator<<(std::ostream& o, const Data& ptr);
void print(uintptr_t raw);

#endif  // CIRCLE_04_CPP_MODULE_06_EX01_DATA_HPP_
