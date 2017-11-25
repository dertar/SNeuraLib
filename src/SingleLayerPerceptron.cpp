#include "SingleLayerPerceptron.hpp"

SingleLayerPerceptron::SingleLayerPerceptron (
    const int inputs,
    const int outputs,
    ActivationFunction *activationFunction,
    const double randFrom,
    const double randTo
  ) :
  Perceptron (
    inputs,
    1,
    outputs,
    activationFunction,
    randFrom,
    randTo
  )
{
}

SingleLayerPerceptron::SingleLayerPerceptron (
    Layers *layers,
    ActivationFunction *activationFunction
  ) :
  Perceptron (
    layers,
    activationFunction
  )
{
}

SingleLayerPerceptron::~SingleLayerPerceptron()
{

}
