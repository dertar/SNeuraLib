#ifndef _NEURON_HPP_
#define _NEURON_HPP_

#include <vector>
#include <cmath>
#include <random>

#include "Exception.hpp"

typedef double Signal;
typedef std::vector<Signal> Signals;

class Neuron
{
private:
  Signals *weights;

public:
  Neuron (Signals *weights);

  Neuron (
    const int inputs,
    const double randFrom = 0.1,
    const double randTo = 0.4
  );

  ~Neuron ();

  Signals* getWeights ();

  double adder (const Signals &inputs);
};

#endif
