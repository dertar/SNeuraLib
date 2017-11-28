#include "Learning.hpp"

Learning::Learning (Perceptron *perceptron)
{
  this->perceptron = perceptron;
}

Learning::~Learning ()
{
}

void Learning::initializeWeights (double min, double max)
{
  std::uniform_real_distribution<double> unif (min, max);
  std::default_random_engine re;

  Layers *layers = this->perceptron->getLayers ();

  for (int l = 0; l < layers->size (); l++)
  {
      Neurons *neurons = layers->at (l);
      for (int n = 0; n < neurons->size (); n++)
      {
        Signals *signals = neurons->at (n)->getWeights ();
        for (int s = 0; s < signals->size (); s++)
        {
          signals-> at(s) = unif (re);
        }
      }
  }
}
