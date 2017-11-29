#ifndef _ACTIVATION_FUNCTION_HPP_
#define _ACTIVATION_FUNCTION_HPP_

#include <cmath>
#include <iostream>

#define ACTIVE 1.0
#define DEACTIVE 0.0

class ActivationFunction
{
private:
  double _threshold;

  double threshold (double x);
public:
  ActivationFunction (double threshold = 0.5);
  ~ActivationFunction ();
  double isActive (double x);
  virtual double function (double x) = 0;
  virtual double derivative (double x) = 0;
};


#endif
