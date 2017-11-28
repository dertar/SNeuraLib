#include "HyperbolicActivationFunction.hpp"

double HyperbolicActivationFunction::function (double x)
{
  return SigmoidActivationFunction::function (x * 2) * 2 - 1;
}

HyperbolicActivationFunction::HyperbolicActivationFunction (double threshold, double slope)
 : SigmoidActivationFunction (threshold, slope)
{

}
