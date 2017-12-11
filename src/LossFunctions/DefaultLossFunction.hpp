#ifndef __DEFAULT_LOSS_FUNCTION_HPP_
#define __DEFAULT_LOSS_FUNCTION_HPP_

#include "LossFunction.hpp"

class DefaultLossFunction
  : virtual public LossFunction
{
public:
  double function (double output, double answer);
  double derivative (double output, double answer);
};

#endif
