#include "SingleLayerPerceptron.hpp"

SingleLayerPerceptron::SingleLayerPerceptron (
    const int inputs,
    const int outputs,
    ActivationFunction *activationFunction
  ) :
  Perceptron (
    inputs,
    1,
    outputs,
    activationFunction
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
