#ifndef _THRESHOLD_FUNCTION_HPP_
#define _THRESHOLD_FUNCTION_HPP_

#include "ActivationFunction.hpp"

class ThresholdFunction :
 public ActivationFunction
{
public:
  ThresholdFunction (double threshold = 0.5);
  double isActive (double sum);
};

#endif
