#ifndef _SINGLE_LAYER_PERCEPTRON_HPP_
#define _SINGLE_LAYER_PERCEPTRON_HPP_
#include <iostream>

#include "Perceptron.hpp"

class SingleLayerPerceptron :
  public Perceptron
{

public:
  SingleLayerPerceptron (
    const int inputs,
    const int outputs,
    ActivationFunction *activationFunction
  );

  SingleLayerPerceptron (
    Layers *layers,
    ActivationFunction *activationFunction
  );

  ~SingleLayerPerceptron ();
};

#endif
