#ifndef _ERROR_CORRECTION_LEARNING_HPP_
#define _ERROR_CORRECTION_LEARNING_HPP_

#include "LearningAgent.hpp"

class ErrorCorrectionLearning :
  public LearningAgent
{
protected:
  double teach (
      Neuron *neuron,
      const Signals &inputs,
      const double errorSignal,
      const double rate = 0.1
    );

public:
  ErrorCorrectionLearning (Perceptron *perceptron);

  ~ErrorCorrectionLearning ();

  int teach (
    const std::vector< Signals > &patterns,
    const std::vector< Signals > &answers,
    const double rate = 0.1,
    const double globalErrorMin = 0.1,
    const int maxIterations = 100
  );

};

#endif
