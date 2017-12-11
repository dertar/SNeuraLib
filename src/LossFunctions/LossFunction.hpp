#ifndef _LOSS_FUNCTION_HPP_
#define _LOSS_FUNCTION_HPP_

#include <cmath>

class LossFunction
{
public:
  virtual double function (double output,double answer) = 0;
  virtual double derivative (double output,double answer) = 0;
};

enum ELOSS_FUNCTION
{
  ELOSS_FUNCTION_SQUARE,
  ELOSS_FUNCTION_DEFAULT
};

enum ELOSS_FUNCTION_D
{
  ELOSS_FUNCTION_D_SQUARE
};

#endif
