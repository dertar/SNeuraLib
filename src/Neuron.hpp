#ifndef _NEURON_HPP_
#define _NEURON_HPP_

#include <vector>

#include "Utils/Exception.hpp"


const static double ZERO_WEIGHT = 1.0;

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

  Signal adder (const Signals &inputs);

  Signal& at (const int index);

  int size ();
};

#endif
