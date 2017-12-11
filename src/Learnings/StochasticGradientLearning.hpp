#ifndef _STOCHASTIC_GRADIENT_LEARNING_HPP_
#define _STOCHASTIC_GRADIENT_LEARNING_HPP_

#include "Learning.hpp"
#include "../SingleLayerPerceptron.hpp"
#include "../LossFunctions/LossFunction.hpp"

class StochasticGradientLearning :
    public Learning
{
private:
  SingleLayerPerceptron *slp;

  double calculateGlobalError (
      const std::vector< Signals > &patterns,
      const std::vector< Signals > &answers,
      const Neurons *neurons
  );

  double calculateCorrectiveGlobalError (
      const double globalError,
      const double errorSignal,
      const double sizePatterns
    );

  double calculateCorrection (
      const Signal outputSignal,
      const Signal inputSignal,
      const Signal answer,
      const double rate
  );
protected:
  LossFunction *lossFunction;

  double teach (
    Neuron *neuron,
    const Signals &inputs,
    const Signal answer,
    const double rate
  );

public:
  StochasticGradientLearning (
    SingleLayerPerceptron *slp,
    LossFunction *lossFunction
  );

  ~StochasticGradientLearning ();

  std::pair<int, float> *teach (
    const std::vector< Signals > &patterns,
    const std::vector< Signals > &answers,
    const double rate = 0.1,
    const double globalErrorMin = 0.1,
    const int maxIterations = 100,
    const bool randomFeed = true
  );

};

#endif
