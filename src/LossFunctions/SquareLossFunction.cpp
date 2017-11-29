#include "SquareLossFunction.hpp"

double SquareLossFunction::function (double output,double answer)
{
  return pow (output - answer, 2);
}

double SquareLossFunction::derivative (double output,double answer)
{
  return -2 * (output - answer);
}
