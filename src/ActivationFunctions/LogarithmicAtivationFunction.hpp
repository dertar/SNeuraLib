#ifndef _LOGARTIHMIC_ACTIVATION_FUNCTION_HPP_
#define _LOGARTIHMIC_ACTIVATION_FUNCTION_HPP_

#include "ActivationFunction.hpp"

class LogarithmicAtivationFunction :
    virtual public ActivationFunction
{
public:
  LogarithmicAtivationFunction (double threshold);
  double function (double x);
};

#endif
