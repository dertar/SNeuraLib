#ifndef _LEARNING_AGENT_HPP_
#define _LEARNING_AGENT_HPP_

#include "Perceptron.hpp"

class LearningAgent
{
protected:
  Perceptron *perceptron;

public:
  LearningAgent(Perceptron *perceptron);

  ~LearningAgent();

  virtual int teach (
    const std::vector< Signals > &patterns,
    const std::vector< Signals > &answers,
    const double rate = 0.1,
    const double globalErrorMin = 0.1,
    const int maxIterations = 100
  ) = 0;
};

#endif
