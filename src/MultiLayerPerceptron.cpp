#include "MultiLayerPerceptron.hpp"

MultiLayerPerceptron::MultiLayerPerceptron (
  const int inputs,
  const int hiddenLayers,
  const int hiddenLayerNeurons,
  const int outputs,
  ActivationFunction *activationFunction
) :
  Perceptron (activationFunction)
{
  this->layers = new Layers (hiddenLayers + 1);

  this->layers->at (0) = this->createLayer (inputs, hiddenLayerNeurons);

  for (int l = 1; l < hiddenLayers; l++)
  {
    this->layers->at (l) = this->createLayer (hiddenLayerNeurons, hiddenLayerNeurons);
  }

  this->layers->at (hiddenLayers) = this->createLayer (
    hiddenLayerNeurons,
    outputs
  );
}


MultiLayerPerceptron::MultiLayerPerceptron (
    Layers *layers,
    ActivationFunction *activationFunction
  ) :
    Perceptron (activationFunction)
{
  this->layers = layers;
}

MultiLayerPerceptron::~MultiLayerPerceptron ()
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

Signals MultiLayerPerceptron::impulse (const Signals &inputs)
{
  Signals ret (inputs);
  for (int l = 0; l < this->layers->size (); l++)
  {
      ret = impulse (ret, l, false);
  }

  return ret;
}

Signals MultiLayerPerceptron::impulse (
    const Signals &inputs,
    const int layer,
    const bool active
  )
{
  Signals ret = this->adder (inputs, layer);
  for (int i = 0; i < ret.size (); i++)
  {
    ret.at (i) =  active ?
     this->activationFunction->isActive (ret.at (i)) :
     this->activationFunction->function (ret.at (i)) ;
  }
  return ret;
}

Signals MultiLayerPerceptron::adder (
    const Signals &inputs,
    const int layer
  )
{
  int size = this->layers->at (layer)->size ();
  Signals ret (size);

  for (int n = 0; n < size; n++)
  {
    ret[n] = this->adder (inputs, layer, n);
  }

  return ret;
}

Signal MultiLayerPerceptron::adder (
    const Signals &inputs,
    const int layer,
    const int neuron
  )
{
  return this->layers->at (layer)->at (neuron)->adder (inputs);
}

Signal MultiLayerPerceptron::impulse (
    const Signals &inputs,
    const int layer,
    const int neuron
  )
{
  return this->activationFunction->function (
    this->adder (inputs, layer, neuron)
  );
}

Layers* MultiLayerPerceptron::getLayers ()
{
  return  this->layers;
}
