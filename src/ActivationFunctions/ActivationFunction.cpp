#include "ActivationFunction.hpp"

ActivationFunction::ActivationFunction (double threshold)
{
  this->_threshold = threshold;
}

double ActivationFunction::isActive (double x)
{
  return this->threshold (
    this->function (x)
  );
}

double ActivationFunction::threshold (double x)
{
  return x >= this->_threshold ? ACTIVE : DEACTIVE;
}
