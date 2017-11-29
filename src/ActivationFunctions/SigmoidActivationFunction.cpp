#include "SigmoidActivationFunction.hpp"

SigmoidActivationFunction::SigmoidActivationFunction (double threshold, double slope) :
    ActivationFunction (threshold)
{
  this->slope = slope;
}

SigmoidActivationFunction::~SigmoidActivationFunction ()
{

}

double SigmoidActivationFunction::function (double x)
{
  return 1 / (1 + exp ( -(this->slope*x) ));
}

double SigmoidActivationFunction::derivative (double x)
{
  return //exp (this->slope * x) / pow (exp (this->slope * x) + 1, 2);
  -exp (this->slope*x);
}
