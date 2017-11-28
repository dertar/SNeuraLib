#ifndef _GAUSSIAN_ACTIVATION_FUNCTION_HPP_
#define _GAUSSIAN_ACTIVATION_FUNCTION_HPP_

#include "ActivationFunction.hpp"

class GaussianActivationFunction :
    virtual public ActivationFunction
{
public:
  GaussianActivationFunction (double threshold = 0.5);
  double function (double x);
};

#endif
