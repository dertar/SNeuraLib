#include "ErrorCorrectionLearning.hpp"

ErrorCorrectionLearning::ErrorCorrectionLearning (SingleLayerPerceptron *slp)
{
  this->slp = slp;
}

ErrorCorrectionLearning::~ErrorCorrectionLearning ()
{
}

std::pair<int, float> *ErrorCorrectionLearning::teach (
    const std::vector< Signals > &patterns,
    const std::vector< Signals > &answers,
    const double rate,
    const double globalErrorMin,
    const int maxIterations,
    const bool randomFeed
  )
{
  int iterations = 0;
  double globalError;

  Neurons *neurons = this->slp->getNeurons ();
  double randWeights = 1.0 / (2.0 * neurons->size ());

  this->initializeWeights (neurons, -randWeights, randWeights);

  do
  {
    globalError = 0.0;
    for (int p = 0; p < patterns.size (); p++)
    {
      for (int n = 0; n < neurons->size (); n++)
      {
        Signal output = this->slp->impulse (patterns.at (p), n);
        double errorSignal = answers.at (p).at (n) - output;
        double changed = this->teach (
          neurons->at (n), patterns.at (p), errorSignal, rate
        );
        globalError += fabs (errorSignal);
      }
    }
  }while (
    globalError > globalErrorMin &&
    ++iterations < maxIterations
  );

  return new std::pair<int, float> (iterations, globalError);
}

double ErrorCorrectionLearning::teach (
    Neuron *neuron,
    const Signals &inputs,
    const double errorSignal,
    const double rate
  )
{
  Signals *weights = neuron->getWeights ();

  if (weights->size () - 1 != inputs.size ())
    throw new Exception ("inputs and weights vectors are not equals");

  double correction = rate * errorSignal * ZERO_WEIGHT,
         globalCorrection = fabs (correction);

  weights->at (0) += correction;

  for (int i = 1; i < weights->size (); i++)
  {
    correction = rate * errorSignal * inputs[i - 1];
    weights->at (i) += correction;
    globalCorrection += fabs (correction);
  }

  return globalCorrection;
}
