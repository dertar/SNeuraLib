#include "Perceptron.hpp"

Perceptron::Perceptron (
    ActivationFunction *activationFunction
  )
{
  this->activationFunction = activationFunction;
}

Perceptron::~Perceptron ()
{

}

ActivationFunction* Perceptron::getActivationFunction()
{
  return this->activationFunction;
}

Neurons* Perceptron::createLayer (
    const int inputs,
    const int outputs
  )
{
  Neurons *ret = new Neurons (outputs);

  for (int n = 0; n < outputs; n++)
  {
    ret->at (n) = new Neuron (inputs);
  }
  return ret;
}
