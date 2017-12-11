#include "SingleLayerPerceptron.hpp"

SingleLayerPerceptron::SingleLayerPerceptron (
    const int inputs,
    const int outputs,
    ActivationFunction *activationFunction
  ) :
  Perceptron (
    activationFunction
  )
{
  this->neurons = this->createLayer (inputs, outputs);
}

SingleLayerPerceptron::SingleLayerPerceptron (
    Neurons *neurons,
    ActivationFunction *activationFunction
  ) :
  Perceptron (
    activationFunction
  )
{
  this->neurons = neurons;
}

SingleLayerPerceptron::~SingleLayerPerceptron ()
{
  for (int n = 0; n < this->neurons->size (); n++)
  {
    delete this->neurons->at (n);
  }
  this->neurons->clear ();
  delete this->neurons;
}

Neurons* SingleLayerPerceptron::getNeurons ()
{
  return this->neurons;
}

Signals SingleLayerPerceptron::impulse (const Signals &inputs)
{
  Signals ret (this->neurons->size ());
  for (int n = 0; n < ret.size (); n++)
  {
      ret.at (n) = this->impulse (inputs, n);
  }
  return ret;
}

Signal SingleLayerPerceptron::impulse (
    const Signals &inputs,
    const int iNeuron
  )
{
  return this->activationFunction->isActive (
    this->adder (inputs, iNeuron)
  );
}

Signal SingleLayerPerceptron::adder (
    const Signals &inputs,
    const int iNeuron
  )
{
  return this->neurons->at (iNeuron)->adder (inputs);
}
