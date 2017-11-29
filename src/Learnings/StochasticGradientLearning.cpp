#include "StochasticGradientLearning.hpp"
#include "ErrorCorrectionLearning.hpp"

StochasticGradientLearning::StochasticGradientLearning (
  SingleLayerPerceptron *perceptron,
  LossFunction *lossFunction
) :
    Learning (perceptron)
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
      double output = this->perceptron-> impulse (patterns.at (p), 0, n);

      sum += this->lossFunction-> function (output, answer);
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

int StochasticGradientLearning::teach (
    const std::vector< Signals > &patterns,
    const std::vector< Signals > &answers,
    const double rate,
    const double globalErrorMin,
    const int maxIterations
  )
{
  int iterations = 0;

  Neurons *neurons = this->perceptron->getLayers ()->at (0);

  double rndWeight = 1/(2*neurons->size ());
  this->initializeWeights (-rndWeight, rndWeight);

  double errorSignal, globalError ;

  do
  {
    globalError = this->calculateGlobalError (patterns, answers, neurons);
    std::vector<int> sequence;
    this->generateShuffledSequence (sequence, patterns.size ());

    while (!sequence.empty ())
    {
      int p = sequence.at (0);
      sequence.erase(sequence.begin ());

      for (int n = 0; n < neurons->size (); n++)
      {
        Signal output = this->perceptron->impulse (patterns.at (p), 0, n, true);

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

    if (++iterations >= maxIterations)
    {
      throw new Exception ("ERL can't train, reached all iterations");
    }
  }while (globalError > globalErrorMin);

  return iterations;
}

double StochasticGradientLearning::calculateCorrection (
    const Signal outputSignal,
    const Signal inputSignal,
    const Signal answer,
    const double rate
)
{
  return rate * this->lossFunction->derivative (outputSignal, answer)
    * this->perceptron->getActivationFunction ()->derivative (outputSignal)
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

  double output = this->perceptron->getActivationFunction ()-> isActive (neuron->adder (inputs));
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
