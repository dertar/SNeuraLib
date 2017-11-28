#include "SigmoidActivationFunction.hpp"

SigmoidActivationFunction::SigmoidActivationFunction (double threshold, double slope) :
    ActivationFunction (threshold)
{
  this->slope = slope;
}

double SigmoidActivationFunction::function (double x)
{
  return 1 / (1 + exp ( -(this->slope*x) ));
}
