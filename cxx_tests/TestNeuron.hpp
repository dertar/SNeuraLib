#include <cxxtest/TestSuite.h>
#include "Utils.cpp"
#include <iostream>

class TestNeuron : public CxxTest::TestSuite
{
private:

public:
    void testCreateNeuron0(void)
    {
      Neuron neuron = Neuron(2);
      std::vector<double> v = *neuron.getWeights();

      TSM_ASSERT("correct size", 3 == v.size());
      TSM_ASSERT_DIFFERS("check if weights are randomized for new neuron",
           0.0, Utils::Sum(v));
    }

    void testCreateNeuron1(void)
    {
      std::vector<double> weights {-1, 0.3, 0.4};
      Neuron neuron = Neuron (&weights);
      std::vector<double> v = *neuron.getWeights();

      TSM_ASSERT("correct size", 3 == v.size());
      TS_ASSERT(-1 == v[0]);
      TS_ASSERT(0.3 == v[1]);
      TS_ASSERT(0.4 == v[2]);

      TSM_ASSERT_DELTA("correct sum ", -0.3 , Utils::Sum(v), 0.1);
    }

    void testAdder0(void)
    {
      std::vector<double> weights {-1.0, 1.0, 0.0};
      Neuron neuron = Neuron (&weights);
      std::vector<double> impulse {1.0, 1.0};
      double adder = neuron.adder (impulse);

      TSM_ASSERT_DELTA("correct adder ", 2.0 , adder, 0.1);
    }

    void testAdder1(void)
    {
      std::vector<double> weights {1.0, 1.0, 1.0};
      Neuron neuron = Neuron(&weights);
      std::vector<double> impulse {1.0, 1.0};
      double adder = neuron.adder (impulse);

      TSM_ASSERT_DELTA("correct adder ", 1.0 , adder, 0.1);
    }
};
