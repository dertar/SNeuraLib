#include "Neuron.hpp"

Signal Neuron::adder (const Signals &inputs)
{
  if (inputs.size () != this->weights->size () - 1)
    throw new Exception ("inputs and weights vectors are not equals");

  double amount = ZERO_WEIGHT * this->weights->at (0);

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

int Neuron::size ()
{
  return this->weights->size ();
}


Neuron::~Neuron ()
{
  this->weights->clear ();
  delete this->weights;
}

Signal& Neuron::at(const int index)
{
  return this->weights->at (index);
}
