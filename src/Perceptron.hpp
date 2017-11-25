#ifndef _PERCEPTRON_HPP_
#define _PERCEPTRON_HPP_

#include "Neuron.hpp"
#include "ActivationFunction.hpp"

typedef std::vector<Neuron*> Neurons;
typedef std::vector<Neurons*> Layers;

class Perceptron
{
protected:
  Layers *layers;
  ActivationFunction *activationFunction;

  Perceptron (
    const int inputs,
    const int layers,
    const int outputs,
    ActivationFunction *activationFunction,
    const double randFrom = 0.1,
    const double randTo = 0.4
  );

  Perceptron (
    Layers *layers,
    ActivationFunction *activationFunction
  );
public:
  Signals impulse (const Signals &inputs);

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

  Layers* getLayers ();

  ~Perceptron ();
};
#endif
