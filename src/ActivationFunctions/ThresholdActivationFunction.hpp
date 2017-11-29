#ifndef _THRESHOLD_ACTIVATION_FUNCTION_HPP_
#define _THRESHOLD_ACTIVATION_FUNCTION_HPP_

#include "ActivationFunction.hpp"

class ThresholdActivationFunction :
    virtual public ActivationFunction
{
public:
  ThresholdActivationFunction (double threshold = 0.5);
  double function (double x);
  double derivative (double x);
};

#endif
