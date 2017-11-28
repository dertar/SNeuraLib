#ifndef _LINEAR_ACTIVATION_FUNCTION_HPP_
#define _LINEAR_ACTIVATION_FUNCTION_HPP_

#include "ActivationFunction.hpp"

class LinearActivationFunction :
    virtual public ActivationFunction
{
private:
  double slope;
  double b;

public:
  LinearActivationFunction (double threshold = 0.5, double slope = 1.0, double b = 0.0);
  double function (double x);
};

#endif
