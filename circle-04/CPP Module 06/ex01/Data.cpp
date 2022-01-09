// Copyright @bigpel66

#include "Data.hpp"

const std::string& Data::getModel(void) const {
  return _model;
}

const int& Data::getSerial(void) const {
  return _serial;
}

const double& Data::getPrice(void) const {
  return _price;
}

const float& Data::getWeight(void) const {
  return _weight;
}

Data& Data::operator=(const Data& d) {
  if (this != &d) {
    _model = d.getModel();
    _serial = d.getSerial();
    _price = d.getPrice();
    _weight = d.getWeight();
  }
  return *this;
}

Data::Data(void)
  : _model("iPhone 13 mini"), _serial(2481), _price(999.0), _weight(140.0) {}

Data::Data(const std::string& model, int serial, double price, float weight)
  : _model(model), _serial(serial), _price(price), _weight(weight) {}

Data::Data(const Data& d)
  : _model(d.getModel()), _serial(d.getSerial()),
    _price(d.getPrice()), _weight(d.getWeight()) {}

Data::~Data(void) {}

uintptr_t serialize(Data* ptr) {
  return reinterpret_cast<uintptr_t>(ptr);
}

Data* deserialize(uintptr_t raw) {
  return reinterpret_cast<Data*>(raw);
}

std::ostream& operator<<(std::ostream& o, const Data& ptr) {
  return o << "Address : " << &ptr << std::endl
          << "Model : " << ptr.getModel() << std::endl
          << "Serial : " << ptr.getSerial() << std::endl
          << "Price : " << ptr.getPrice() << std::endl
          << "Weight : " << ptr.getWeight() << std::endl << std::endl;
}

void print(uintptr_t raw) {
  Data *d = deserialize(raw);
  if (!d)
    return;
  std::cout << "Address : " << d << std::endl
    << "Model : " << d->getModel() << std::endl
    << "Serial : " << d->getSerial() << std::endl
    << "Price : " << d->getPrice() << std::endl
    << "Weight : " << d->getWeight() << std::endl << std::endl;
}
