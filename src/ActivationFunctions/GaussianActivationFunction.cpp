#include "GaussianActivationFunction.hpp"

GaussianActivationFunction::GaussianActivationFunction (double threshold) :
    ActivationFunction (threshold)
{

}

double GaussianActivationFunction::function (double x)
{
  return exp (-(x*x) / 2);
}
