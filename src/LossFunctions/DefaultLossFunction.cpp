#include "DefaultLossFunction.hpp"

double DefaultLossFunction::function (double output, double answer)
{
  return output - answer;
}

double DefaultLossFunction::derivative (double output ,double answer)
{
  return -1;
}
