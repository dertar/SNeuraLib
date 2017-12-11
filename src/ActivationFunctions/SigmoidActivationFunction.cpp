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
  double sigm = this->function (x);
  return sigm * (1 - sigm);
  //(this->slope * exp ( -(this->slope * x) )) / pow (exp ( -(this->slope * x) ) + 1, 2);
}
