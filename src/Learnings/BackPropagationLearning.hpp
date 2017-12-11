#ifndef _BACK_PROPAGATION_HPP_
#define _BACK_PROPAGATION_HPP_

#include "../MultiLayerPerceptron.hpp"
#include "../ActivationFunctions.hpp"
#include "Learning.hpp"

class BackPropagationLearning :
    public Learning
{
private:
  MultiLayerPerceptron *mlp;

  std::vector< Signals* >* forwardpass (
    const Signals &impulse,
    const Layers *layers
  );

  std::vector< Signals* >* backwardpass (
      std::vector< Signals* >* forwardpass,
      const Layers *layers,
      Signal answer,
      const int iTeachNeuron
  );

  Signals* getLastLayerErrors (
      Neuron *neuronInLastLayer,
      const Signal error
  );

  Signals* getLayerErrors (
    Neurons *layer,
    Neurons *layerForward,
    Signals *errorsForward
  );

  void applyErrors (
    Layers *layers,
    std::vector< Signals* >* forwardpass,
    std::vector< Signals* >* backwardpass,
    const int iTeachNeuron,
    const double rate = 0.1
  );

  Signals activeSignals (const Signals &signals);



public:
  BackPropagationLearning (
    MultiLayerPerceptron *mlp,
    ELOSS_FUNCTION eloss_function
  );

  std::pair<int, float> *teach (
    const std::vector< Signals > &patterns,
    const std::vector< Signals > &answers,
    const double rate = 0.1,
    const double globalErrorMin = 0.1,
    const int maxIterations = 100,
    const bool randomFeed = false
  );

};

#endif
