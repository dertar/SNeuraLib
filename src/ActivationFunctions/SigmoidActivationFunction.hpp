#ifndef _SIGMOID_ACTIVATION_FUNCTION_HPP_
#define _SIGMOID_ACTIVATION_FUNCTION_HPP_

#include "ActivationFunction.hpp"

class SigmoidActivationFunction :
    virtual public ActivationFunction
{
protected:
  double slope;
public:
  SigmoidActivationFunction (double threshold = 0.5, double slope = 1.0);
  ~SigmoidActivationFunction ();
  double function (double x);
  double derivative (double x);
};

#endif
