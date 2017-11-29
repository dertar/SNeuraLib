#ifndef _SQUARE_LOSS_FUNCTION_HPP_
#define _SQUARE_LOSS_FUNCTION_HPP_

#include "LossFunction.hpp"

class SquareLossFunction :
    virtual public LossFunction
{
public:
  double function (double output,double answer);
  double derivative (double output,double answer);
};

#endif
