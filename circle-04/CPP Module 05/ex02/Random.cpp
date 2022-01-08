// Copyright @bigpel66

#include "Random.hpp"

int Random::seed = 0;

Random::Random(void) {}
Random::~Random(void) {}

double Random::randv(void) {
  seed = (seed * 1103515245 + 12345) & 0x7fffffff;
  return static_cast<double>(seed) / static_cast<double>(0x80000000);
}

double Random::randr(double min, double max) {
  return (randv() * (max - min)) + min;
}
