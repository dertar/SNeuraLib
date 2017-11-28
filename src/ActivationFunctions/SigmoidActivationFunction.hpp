#ifndef _SIGMOID_ACTIVATION_FUNCTION_HPP_
#define _SIGMOID_ACTIVATION_FUNCTION_HPP_

#include "ActivationFunction.hpp"

class SigmoidActivationFunction :
    virtual public ActivationFunction
{
protected:
  double slope;
public:
  SigmoidActivationFunction (double threshold, double slope = 1.0);
  double function (double x);
};

#endif
