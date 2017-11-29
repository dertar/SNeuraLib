#include "Perceptron.hpp"

Perceptron::Perceptron (
    const int inputs,
    const int layers,
    const int outputs,
    ActivationFunction *activationFunction
  )
{
  this->layers = new Layers (layers);

  for (int l = 0; l < layers; l++)
  {
    this->layers->at (l) = new Neurons (outputs);
    for (int i = 0; i < outputs; i++)
    {
      this->layers->at (l)->at (i) = new Neuron (inputs);
    }
  }
  this->activationFunction = activationFunction;
}

Perceptron::Perceptron (
    Layers *layers,
    ActivationFunction *activationFunction
  )
{
  this->layers = layers;
  this->activationFunction = activationFunction;
}

Perceptron::~Perceptron ()
{
  for (int i = 0; i < this->layers->size (); i++)
  {
    this->layers->at (i)->clear ();
    delete this->layers->at (i);
  }
  this->layers->clear ();
  delete this->layers;
  //delete this->activationFunction;
}

Signals Perceptron::impulse (const Signals &inputs)
{
  Signals ret (inputs);
  for (int l = 0; l < this->layers->size (); l++)
  {
      ret = impulse (ret, l);
  }
  return ret;
}

Signals Perceptron::impulse (
    const Signals &inputs,
    const int layer
  )
{
  int size = this->layers->at (layer)->size ();
  Signals ret (size);

  for (int n = 0; n < size; n++)
  {
    ret[n] = this->impulse (inputs, layer, n);
  }

  return ret;
}

Signal Perceptron::impulse (
    const Signals &inputs,
    const int layer,
    const int neuron,
    const bool activeFunction
)
{
  Signal ret = this->layers->at (layer)->at (neuron)->adder (inputs);

  return activeFunction ?
      this->activationFunction->isActive (ret) :
      ret;
}

Layers* Perceptron::getLayers ()
{
  return this->layers;
}

ActivationFunction* Perceptron::getActivationFunction()
{
  return this->activationFunction;
}


double Perceptron::isActive (const Signal output)
{
  return this->activationFunction->isActive (output);
}
