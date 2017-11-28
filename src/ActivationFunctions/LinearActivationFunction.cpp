#include "LinearActivationFunction.hpp"

double LinearActivationFunction::function (double x)
{
  return this->slope * x + this->b;
}

LinearActivationFunction::LinearActivationFunction (double threshold, double slope, double b) :
    ActivationFunction (threshold)
{
  this->slope = slope;
  this->b = b;
}
