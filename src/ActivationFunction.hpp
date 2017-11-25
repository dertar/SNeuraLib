#ifndef _ACTIVATION_FUNCTION_HPP_
#define _ACTIVATION_FUNCTION_HPP_

#define ACTIVE 1.0
#define DEACTIVE 0.0

class ActivationFunction
{
protected:
  double threshold;
public:
  ActivationFunction (double threshold = 0.5);
  double getThreshold ();
  virtual double isActive (double sum) = 0;
};

#include "ThresholdFunction.hpp"
#endif
