#include "ActivationFunction.hpp"

ActivationFunction::ActivationFunction (double threshold)
{
  this->_threshold = threshold;
}

double ActivationFunction::isActive (double x)
{
  double func = this->function (x);
  double threshold = this->threshold(func);

  return threshold;
  // return this->threshold (
  //   this->function (x)
  // );
}

double ActivationFunction::threshold (double x)
{
  return x >= this->_threshold ? ACTIVE : DEACTIVE;
}

ActivationFunction::~ActivationFunction ()
{

}

bool ActivationFunction::Threshold (double x, double threshold)
{
  return x >= threshold ? true : false;
}

std::vector<bool> *ActivationFunction::ActiveImpulse (
    Signals &signals,
    double threshold
  )
{
  std::vector<bool> *ret = new std::vector<bool> (signals.size ());

  for (int i = 0; i < ret->size (); i++)
  {
    ret->at (i) = ActivationFunction::Threshold
      (signals.at (i), threshold);
  }

  return  ret;
}
