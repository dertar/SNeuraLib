#ifndef _SINGLE_LAYER_PERCEPTRON_HPP_
#define _SINGLE_LAYER_PERCEPTRON_HPP_
#include <iostream>

#include "Perceptron.hpp"

class SingleLayerPerceptron :
  public Perceptron
{
private:
  Neurons *neurons;

public:
  SingleLayerPerceptron (
    const int inputs,
    const int outputs,
    ActivationFunction *activationFunction
  );

  SingleLayerPerceptron (
    Neurons *neurons,
    ActivationFunction *activationFunction
  );

  ~SingleLayerPerceptron ();

  Signals impulse (const Signals &inputs);

  Signal impulse (
      const Signals &inputs,
      const int iNeuron
    );

  Signal adder (
      const Signals &inputs,
      const int iNeuron
    );

  Neurons* getNeurons ();
};

#endif
