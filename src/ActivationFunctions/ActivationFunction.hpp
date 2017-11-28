#ifndef _ACTIVATION_FUNCTION_HPP_
#define _ACTIVATION_FUNCTION_HPP_

#include <cmath>

#define ACTIVE 1.0
#define DEACTIVE 0.0

class ActivationFunction
{
private:
  double _threshold;

  double threshold (double x);
public:
  ActivationFunction (double threshold = 0.5);

  double isActive (double x);
  virtual double function (double x) = 0;
};


#endif
