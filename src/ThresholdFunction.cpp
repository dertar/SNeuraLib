#include "ThresholdFunction.hpp"

double ThresholdFunction::isActive (double sum)
{
  return sum >= this->threshold ? ACTIVE : DEACTIVE;
}

ThresholdFunction::ThresholdFunction (double threshold)
 : ActivationFunction (threshold)
{
}
