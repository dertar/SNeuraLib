#include "Learning.hpp"

Learning::Learning (Perceptron *perceptron)
{
  this->perceptron = perceptron;
  this->re = new std::default_random_engine;
}

Learning::~Learning ()
{
  delete this->re;
}


void Learning::generateSequence (
    std::vector<int> &sequence,
    const int size
  )
{
  sequence.clear ();

  for(int i = 0; i < size; i++)
  {
    sequence.push_back (i);
  }
}

void Learning::generateShuffledSequence (
    std::vector<int> &sequence,
    const int size
  )
{
  std::vector<int> tmp;
  this->generateSequence (tmp, size);
  sequence.clear ();
  for (int i = 0; i < size; i++)
  {
    std::uniform_real_distribution<double> unif (0, tmp.size() - 1);
    int randomed = unif (*re);
    sequence.push_back (tmp.at(randomed));
    tmp.erase (tmp.begin() + randomed);
  }
}

void Learning::initializeWeights (double min, double max)
{
  std::uniform_real_distribution<double> unif (min, max);

  Layers *layers = this->perceptron->getLayers ();

  for (int l = 0; l < layers->size (); l++)
  {
      Neurons *neurons = layers->at (l);
      for (int n = 0; n < neurons->size (); n++)
      {
        Signals *signals = neurons->at (n)->getWeights ();
        for (int s = 0; s < signals->size (); s++)
        {
          signals-> at(s) = unif (*re);
        }
      }
  }
}
