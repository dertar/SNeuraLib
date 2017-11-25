#include "ActivationFunction.hpp"

ActivationFunction::ActivationFunction (double threshold)
{
  this->threshold = threshold;
}

double ActivationFunction::getThreshold ()
{
  return this->threshold;
}
