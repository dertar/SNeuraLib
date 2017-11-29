#ifndef _HYPERBOLIC_ACTIVATION_FUNCTION_HPP_
#define _HYPERBOLIC_ACTIVATION_FUNCTION_HPP_

#include "SigmoidActivationFunction.hpp"

class HyperbolicActivationFunction :
  public SigmoidActivationFunction
{
public:
  HyperbolicActivationFunction (double threshold = 0.5, double slope = 1.0);
  ~HyperbolicActivationFunction ();
  double function (double x);
  double derivative (double x);
};

#endif
