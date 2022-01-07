// Copyright @bigpel66

#ifndef CIRCLE_04_CPP_MODULE_01_EX01_RANDOM_HPP_
#define CIRCLE_04_CPP_MODULE_01_EX01_RANDOM_HPP_

class Random {
 private:
  static int seed;

  Random(void);
  ~Random(void);

 public:
  static double randv(void);
  static double randr(double min, double max);
};

#endif  // CIRCLE_04_CPP_MODULE_01_EX01_RANDOM_HPP_
