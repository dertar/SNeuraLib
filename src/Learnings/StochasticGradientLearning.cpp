#include "StochasticGradientLearning.hpp"
#include "ErrorCorrectionLearning.hpp"

StochasticGradientLearning::StochasticGradientLearning (
  SingleLayerPerceptron *perceptron,
  LossFunction *lossFunction
)
{
  this->lossFunction = lossFunction;
}

StochasticGradientLearning::~StochasticGradientLearning ()
{
}

double StochasticGradientLearning::calculateGlobalError (
    const std::vector< Signals > &patterns,
    const std::vector< Signals > &answers,
    const Neurons *neurons
)
{
  double sum = 0.0;
  for(int p = 0; p < patterns.size (); p++)
  {
    for (int n = 0; n < neurons->size (); n++)
    {
      double answer = answers.at (p).at (n);
      double output = this->slp->impulse (patterns.at (p), n);

      sum += this->lossFunction->function (output, answer);
    }
  }
  return sum;
}

double StochasticGradientLearning::calculateCorrectiveGlobalError (
    const double globalError,
    const double errorSignal,
    const double sizePatterns
  )
{
  return ((sizePatterns - 1.0) / sizePatterns) * globalError + 1.0/sizePatterns * (errorSignal * errorSignal);
}

std::pair<int, float> *StochasticGradientLearning::teach (
    const std::vector< Signals > &patterns,
    const std::vector< Signals > &answers,
    const double rate,
    const double globalErrorMin,
    const int maxIterations,
    const bool randomFeed
  )
{
  int iterations = 0;

  Neurons *neurons = this->slp->getNeurons ();

  double rndWeight = 1/(2*neurons->size ());

  this->initializeWeights (neurons, -rndWeight, rndWeight);

  double errorSignal, globalError;
  int p;
  do
  {
    globalError = this->calculateGlobalError (patterns, answers, neurons);
    std::vector<int> sequence;
    this->generateSequence (patterns.size (), randomFeed);

    while (!this->isOverBatch ())
    {
      int p = this->getIndexOfPattern ();

      for (int n = 0; n < neurons->size (); n++)
      {
        Signal output = this->slp->impulse (patterns.at (p), n);

        errorSignal = this->lossFunction->function (
          output,
          answers.at (p).at (n)
        );

        double changed = this->teach (
          neurons->at (n), patterns.at (p), answers.at(p).at(n) , rate
        );

        globalError = this->calculateCorrectiveGlobalError (
            globalError,
            errorSignal,
            patterns.size ()
        );

      }
    }

  }while (
    globalError > globalErrorMin &&
    ++iterations < maxIterations
  );

  return new std::pair<int, float> (iterations, globalError);
}

double StochasticGradientLearning::calculateCorrection (
    const Signal outputSignal,
    const Signal inputSignal,
    const Signal answer,
    const double rate
)
{
  return rate * this->lossFunction->derivative (outputSignal, answer)
    * this->slp->getActivationFunction ()->derivative (outputSignal)
    * inputSignal;
}

double StochasticGradientLearning::teach (
    Neuron *neuron,
    const Signals &inputs,
    const Signal answer,
    const double rate
  )
{
  Signals *weights = neuron->getWeights ();

  if (weights->size () - 1 != inputs.size ())
    throw new Exception ("inputs and weights vectors are not equals");

  double output = this->slp->getActivationFunction ()-> isActive (neuron->adder (inputs));
  double correction = this->calculateCorrection (output, -1.0, answer, rate);
  double globalCorrection = fabs (correction);

  weights->at (0) -= correction;

  for (int i = 1; i < weights->size (); i++)
  {
    correction = this->calculateCorrection (output, inputs[i - 1], answer, rate);
    weights->at (i) -= correction;
    globalCorrection += fabs (correction);
  }

  return globalCorrection;
}
