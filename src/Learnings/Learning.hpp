#ifndef _LEARNING_HPP_
#define _LEARNING_HPP_

#include <random>
#include <queue>

#include "../Perceptron.hpp"
#include "../LossFunctions.hpp"

class Learning
{
private:
  int iPattern;
  std::vector < int > *sequence;

std::vector<int> *generateSequenceArray (
  const int size
);

void generateShuffledSequence (
    const int size
);

protected:
  std::default_random_engine *re;
  LossFunction *lossFunction;

  void initializeWeights (
    Neurons *neurons,
    double min = 0.1,
    double max = 0.3
  );

  void generateSequence (
    const int size,
    const bool shuffle = false
  );

  bool isOverBatch ();
  void nextPattern ();
  int getIndexOfPattern ();

public:
  Learning ();

  ~Learning ();

  virtual std::pair<int, float> *teach (
    const std::vector< Signals > &patterns,
    const std::vector< Signals > &answers,
    const double rate = 0.1,
    const double globalErrorMin = 0.1,
    const int maxIterations = 100,
    const bool randomFeed = false
  ) = 0;
};

enum PATTERN_FEED
{
  SEQUENCE,
  RANDOM
};

#endif
