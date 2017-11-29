#include "ThresholdActivationFunction.hpp"

double ThresholdActivationFunction::function (double x)
{
  return x;
}

double ThresholdActivationFunction::derivative (double x)
{
  return 1;
}


ThresholdActivationFunction::ThresholdActivationFunction (double threshold) :
    ActivationFunction (threshold)
{
}
