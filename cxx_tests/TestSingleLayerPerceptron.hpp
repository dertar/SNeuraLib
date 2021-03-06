#include <cxxtest/TestSuite.h>
#include "../src/SingleLayerPerceptron.hpp"
#include "../src/ActivationFunctions.hpp"
#include "Utils.cpp"

class TestSingleLayerPerceptron : public CxxTest::TestSuite
{
private:

public:
    void testCreateLayer (void)
    {
      SingleLayerPerceptron slp (2, 2, new ThresholdActivationFunction ());

      Neurons *neurons = slp.getNeurons ();

      TSM_ASSERT("correct size", 2 == neurons->size ());
      for (int i = 0; i < neurons->size (); i++)
      {
        std::vector<double> *v = neurons->at (i)->getWeights ();
        TS_ASSERT (0.0 == Utils::Sum (*v));
      }
    }

    void testImpulse0(void)
    {
      std::vector<double> weights {-1, 0.3, 0.4};
      Neurons *neurons = new Neurons(1);
      neurons->at (0) = new Neuron (&weights);

      SingleLayerPerceptron slp (neurons, new ThresholdActivationFunction ());
      Signals impulse {1.0, 1.0};

      Signal s = slp.adder (impulse, 0);

      TSM_ASSERT_DELTA("correct impulse ", 1.7 , s, 0.1);
    }

    void testImpulse1(void)
    {
      std::vector<double> weights {0.73, -0.41, 0.08};
      Neurons *neurons = new Neurons(1);
      neurons->at (0) = new Neuron (&weights);

      SingleLayerPerceptron slp (neurons, new ThresholdActivationFunction ());
      Signals impulse {1, -0.4};

      Signal s = slp.adder (impulse, 0);

      TSM_ASSERT_DELTA("correct impulse ", -1.172 , s, 0.001);
    }
};
