#ifndef _PERCEPTRON_HPP_
#define _PERCEPTRON_HPP_

#include "Neuron.hpp"
#include "ActivationFunctions/ActivationFunction.hpp"
#include <iostream>

typedef std::vector<Neuron*> Neurons;
typedef std::vector<Neurons*> Layers;

class Perceptron
{
protected:
  ActivationFunction *activationFunction;

public:
  Perceptron (ActivationFunction *activeFunction);

  ~Perceptron ();

  virtual Signals impulse (const Signals &inputs) = 0;

  Signals impulse (
    const Signals &inputs,
    const int layer
  );

  Signal impulse (
      const Signals &inputs,
      const int layer,
      const int neuron,
      const bool activeFunction = true
  );

  Neurons* createLayer (
    const int inputs,
    const int outputs
  );

  ActivationFunction* getActivationFunction ();
};
#endif
