#include "Neuron.hpp"

double Neuron::adder (const Signals &inputs)
{
  if (inputs.size () != this->weights->size () - 1)
    throw new Exception ("inputs and weights vectors are not equals");

  double amount = -1.0 * this->weights->at (0);

  for (int i = 1; i < this->weights->size (); i++)
  {
    amount += inputs[i - 1] * this->weights->at (i);
  }
  return amount;
}

Neuron::Neuron (Signals *weights)
{
  this->weights = weights;
}

Neuron::Neuron (const int inputs)
{
  this->weights = new Signals (inputs + 1);
}

Signals* Neuron::getWeights ()
{
  return this->weights;
}

Neuron::~Neuron ()
{
  this->weights->clear ();
  delete this->weights;
}
