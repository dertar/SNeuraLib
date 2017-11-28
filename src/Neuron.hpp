#ifndef _NEURON_HPP_
#define _NEURON_HPP_

#include <vector>

#include "Utils/Exception.hpp"

typedef double Signal;
typedef std::vector<Signal> Signals;

class Neuron
{
private:
  Signals *weights;

public:
  Neuron (Signals *weights);

  Neuron (const int inputs);

  ~Neuron ();

  Signals* getWeights ();

  double adder (const Signals &inputs);
};

#endif
