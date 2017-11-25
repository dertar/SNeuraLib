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

Neuron::Neuron (
    const int inputs,
    const double randFrom,
    const double randTo
  )
{
  this->weights = new Signals;
  std::uniform_real_distribution<double> unif (randFrom,randTo);
  std::default_random_engine re;

  for(int i = 0; i < inputs + 1; i++)
  {
    this->weights->push_back (unif (re));
  }

  this->weights = weights;
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
