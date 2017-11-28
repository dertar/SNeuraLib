#include "ThresholdActivationFunction.hpp"

double ThresholdActivationFunction::function (double x)
{
  return x;
}

ThresholdActivationFunction::ThresholdActivationFunction (double threshold) :
    ActivationFunction (threshold)
{
}
