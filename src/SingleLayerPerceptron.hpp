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
    ActivationFunction *activationFunction,
    const double randFrom = 0.1,
    const double randTo = 0.4
  );

  SingleLayerPerceptron (
    Layers *layers,
    ActivationFunction *activationFunction
  );

  ~SingleLayerPerceptron ();
};

#endif
