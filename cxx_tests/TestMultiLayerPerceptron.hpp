#include <cxxtest/TestSuite.h>
#include "../src/MultiLayerPerceptron.hpp"
#include "../src/ActivationFunctions.hpp"
#include "Utils.cpp"

class TestMultiLayerPerceptron : public CxxTest::TestSuite
{
private:

public:
  void testCreateMLP(void)
  {
    MultiLayerPerceptron mlp (2, 1, 1, 1, new SigmoidActivationFunction());
    Layers* layers = mlp.getLayers ();

    TS_ASSERT(layers->size () == 2);

    TS_ASSERT(layers->at (0)->size () == 1);

    TS_ASSERT(layers->at (1)->size () == 1);

    TS_ASSERT(layers->at (0)->at (0)->getWeights()->size () == 3);

    TS_ASSERT(layers->at (1)->at (0)->getWeights()->size () == 2);

  }

  void testImpulse0(void)
  {
    std::vector<double> weights1 {0.33, -0.56};
    Neurons *layer1 = new Neurons(1);
    layer1->at (0) = new Neuron (&weights1);


    std::vector<double> weight2 {1.33, -0.04};
    Neurons *layer2 = new Neurons(1);
    layer2->at (0) = new Neuron (&weight2);

    Layers *layers = new Layers (2);

    layers->at (0) = layer1;
    layers->at (1) = layer2;

    MultiLayerPerceptron mlp (layers, new ThresholdActivationFunction ());

    Signals impulse {1.0};

    Signal first = mlp.adder (impulse, 0, 0);

    TSM_ASSERT_DELTA("correct impulse ", -0.89 , first, 0.1);

    Signals impulse2 {-0.89};
    Signal second = mlp.adder (impulse, 1, 0);

    TSM_ASSERT_DELTA("correct impulse ", -1.2944 , second, 0.1);
  }

  void testImpulse1(void)
  {
    std::vector<double> weights1 {0.77,-0.17, 0.43};
    std::vector<double> weights2 {-0.1, 0.35, 0.81};

    Neurons *layer1 = new Neurons(2);
    layer1->at (0) = new Neuron (&weights1);
    layer1->at (1) = new Neuron (&weights2);

    std::vector<double> weights3 {1.07, 0.04, 0.23};
    std::vector<double> weights4 {0.55, 0.45, -0.18};

    Neurons *layer2 = new Neurons(2);
    layer2->at (0) = new Neuron (&weights3);
    layer2->at (1) = new Neuron (&weights4);


    Layers *layers = new Layers (2);

    layers->at (0) = layer1;
    layers->at (1) = layer2;

    MultiLayerPerceptron mlp (layers, new ThresholdActivationFunction ());

    Signals impulse {0.153, -0.4};
    Signals impulse2 { -0.96801, -0.1704};

    Signal first = mlp.adder (impulse, 0, 0);
    TSM_ASSERT_DELTA("correct impulse ", impulse2[0] , first, 0.001);

    Signal first1 = mlp.adder (impulse, 0, 1);
    TSM_ASSERT_DELTA("correct impulse ", impulse2[1], first1, 0.001);

    Signal second1 = mlp.adder (impulse2, 1, 0);
    TSM_ASSERT_DELTA("correct impulse ", -1.1479 , second1, 0.001);

    Signal second2 = mlp.adder (impulse2, 1, 1);
    TSM_ASSERT_DELTA("correct impulse ", -0.9549 , second2, 0.001);
  }
};
