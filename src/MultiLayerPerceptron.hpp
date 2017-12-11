#ifndef _MULTI_LAYER_PERCEPTRON_HPP_
#define _MULTI_LAYER_PERCEPTRON_HPP_

#include "Perceptron.hpp"

class MultiLayerPerceptron:
    public Perceptron
{
private:
  Layers *layers;

public:
    MultiLayerPerceptron (
      const int inputs,
      const int hiddenLayers,
      const int hiddenLayerNeurons,
      const int outputs,
      ActivationFunction *activationFunction
    );

    MultiLayerPerceptron (
      Layers *layers,
      ActivationFunction *activationFunction
    );

    ~MultiLayerPerceptron ();

    Layers* getLayers ();

    Signals impulse (const Signals &inputs);

    Signals impulse (
        const Signals &inputs,
        const int layer,
        const bool active = false
    );

    Signals adder (
        const Signals &inputs,
        const int layer
    );

    Signal impulse (
        const Signals &inputs,
        const int layer,
        const int neuron
    );

    Signal adder (
        const Signals &inputs,
        const int layer,
        const int neuron
    );
};

#endif
