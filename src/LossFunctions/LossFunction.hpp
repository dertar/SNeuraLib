#ifndef _LOSS_FUNCTION_HPP_
#define _LOSS_FUNCTION_HPP_

#include <cmath>

class LossFunction
{
public:
  virtual double function (double output,double answer) = 0;
  virtual double derivative (double output,double answer) = 0;
};

#endif
