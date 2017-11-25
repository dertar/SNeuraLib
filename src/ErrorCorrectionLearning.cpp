#include "ErrorCorrectionLearning.hpp"

ErrorCorrectionLearning::ErrorCorrectionLearning (Perceptron *perceptron) :
    LearningAgent (perceptron)
{
}

ErrorCorrectionLearning::~ErrorCorrectionLearning ()
{
}

int ErrorCorrectionLearning::teach (
    const std::vector< Signals > &patterns,
    const std::vector< Signals > &answers,
    const double rate,
    const double globalErrorMin,
    const int maxIterations
  )
{
  int iterations = 0;
  double globalError;

  Neurons *neurons = this->perceptron->getLayers ()->at (0);

  do
  {
    globalError = 0.0;
    for (int p = 0; p < patterns.size (); p++)
    {
      for (int n = 0; n < neurons->size (); n++)
      {
        Signal output = this->perceptron->impulse (patterns.at (p), 0, n);
        double errorSignal = answers.at (p).at (n) - output;
        double changed = this->teach (
          neurons->at (n), patterns.at (p), errorSignal, rate
        );

        globalError += fabs (errorSignal);
      }
    }
    if (++iterations >= maxIterations)
    {
      throw new Exception ("ERL can't train, reached all iterations");
    }
  }while (globalError > globalErrorMin);

  return iterations;
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

  double correction = rate * errorSignal * -1.0,
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
