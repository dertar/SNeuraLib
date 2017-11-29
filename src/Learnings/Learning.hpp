#ifndef _LEARNING_HPP_
#define _LEARNING_HPP_

#include <random>
#include <queue>

#include "../Perceptron.hpp"

class Learning
{

protected:
  Perceptron *perceptron;
  std::default_random_engine *re;

  void initializeWeights (double min = 0.1, double max = 0.3);
  void generateShuffledSequence (
      std::vector<int> &sequence,
      const int size
    );

  void generateSequence (
      std::vector<int> &sequence,
      const int size
    );

public:
  Learning(Perceptron *perceptron);

  ~Learning();

  virtual int teach (
    const std::vector< Signals > &patterns,
    const std::vector< Signals > &answers,
    const double rate = 0.1,
    const double globalErrorMin = 0.1,
    const int maxIterations = 100
  ) = 0;

};

#endif
