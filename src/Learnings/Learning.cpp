#include "Learning.hpp"

Learning::Learning ()
{
  this->re = new std::default_random_engine;
  this->sequence = new std::vector<int> ();
}

Learning::~Learning ()
{
  delete this->re;
  delete this->lossFunction;
  delete this->sequence;
}

std::vector<int> *Learning::generateSequenceArray (
    const int size
  )
{
  std::vector<int> *ret = new std::vector<int>(size);

  for(int i = 0; i < size; i++)
  {
    ret->at (i) = i;
  }
  return ret;
}

void Learning::generateSequence (
  const int size,
  const bool shuffle
  )
{
  this->sequence->clear ();
  delete this->sequence;

  if (shuffle)
  {
    this->generateShuffledSequence (size);
  }
  else{
    this->sequence = this->generateSequenceArray (size);
  }

  this->iPattern = 0;
}

int Learning::getIndexOfPattern ()
{
  return this->sequence->at (iPattern);
}

bool Learning::isOverBatch ()
{
  return this->iPattern > this->sequence->size () - 1;
}

void Learning::nextPattern ()
{
  this->iPattern++;
}

void Learning::generateShuffledSequence (
    const int size
  )
{
  std::vector<int> *tmp = this->generateSequenceArray (size);
  this->sequence = new std::vector<int> (size);
  for (int i = 0; i < size; i++)
  {
    std::uniform_real_distribution<double> unif (0, tmp->size() - 1);
    int randomed = unif (*re);
    this->sequence->at (i) = tmp->at(randomed);
    tmp->erase (tmp->begin() + randomed);
  }
  delete tmp;
}

void Learning::initializeWeights (
    Neurons *neurons,
    double min,
    double max
  )
{
  std::uniform_real_distribution<double> unif (min, max);
  for (int n = 0; n < neurons->size (); n++)
  {
    Signals *signals = neurons->at (n)->getWeights ();
    for (int s = 0; s < signals->size (); s++)
    {
      double rnd = unif (*re);
      signals-> at(s) = rnd;
    }
  }
}
