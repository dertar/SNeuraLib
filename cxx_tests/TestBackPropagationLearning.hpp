#include <cxxtest/TestSuite.h>
#include "../src/MultiLayerPerceptron.hpp"
#include "../src/ActivationFunctions.hpp"
#include "Utils.cpp"
#include "../src/Learnings/BackPropagationLearning.hpp"
#include <iostream>
#include <utility>

class TestBackPropagationLearning : public CxxTest::TestSuite
{
public:

    // void testTeachErrorCorrectionNe(void)
    // {
    //   MultiLayerPerceptron mlp(1, 1, 1, 1, new SigmoidActivationFunction ());
    //   BackPropagationLearning teacher (&mlp, ELOSS_FUNCTION_SQUARE);
    //   std::vector<double> p0 = {0};
    //   std::vector<double> p1 = {1};
    //
    //   std::vector<double> a0 = {1};
    //   std::vector<double> a1 = {0};
    //
    //   std::vector< Signals > answers = {a0, a1};
    //
    //   std::vector< Signals > patterns
    //    = {p0, p1};
    //
    //    std::pair<int, float> *info = teacher.teach(patterns, answers, 0.3, 0.1, 7000, false);
    //    std::cout << "teached for " << info->first << " iterations; loss: " << info->second << std::endl;
    //    delete info;
    //
    //    std::cout << "p0: " <<  mlp.impulse (p0)[0] << std::endl;
    //    std::cout << "p1: " <<  mlp.impulse (p1)[0] << std::endl;
    //    TS_ASSERT (ActivationFunction::Threshold( mlp.impulse (p0)[0], 0.5) == true);
    //    TS_ASSERT (ActivationFunction::Threshold( mlp.impulse (p1)[0], 0.5) == false);
    // }

    void testTeachErrorCorrectionOR(void)
    {
      MultiLayerPerceptron mlp(2, 2, 2, 1, new SigmoidActivationFunction ());
      BackPropagationLearning teacher (&mlp, ELOSS_FUNCTION_SQUARE);

      std::vector<double> p0 = {0, 0};
      std::vector<double> p1 = {0, 1};
      std::vector<double> p2 = {1, 0};
      std::vector<double> p3 = {1, 1};

      std::vector<double> a0 = {0};
      std::vector<double> a1 = {1};
      std::vector<double> a2 = {1};
      std::vector<double> a3 = {1};

      std::vector< Signals > answers = {a0, a1, a2, a3};

      std::vector< Signals > patterns
       = {p0, p1, p2, p3};

       std::pair<int, float> *info = teacher.teach(patterns, answers, 0.3, 0.1, 7000, false);
       std::cout << "teached for " << info->first << " iterations; loss: " << info->second << std::endl;
       delete info;

      TS_ASSERT_DELTA(mlp.impulse (p0)[0], answers[0][0], 0.1);
      TS_ASSERT_DELTA(mlp.impulse (p1)[0], answers[1][0], 0.1);
      TS_ASSERT_DELTA(mlp.impulse (p2)[0], answers[2][0], 0.1);
      TS_ASSERT_DELTA(mlp.impulse (p3)[0], answers[3][0], 0.1);
    }

    void testTeachErrorCorrectionAND(void)
    {
      MultiLayerPerceptron mlp(2, 1, 1, 1, new SigmoidActivationFunction ());
      BackPropagationLearning teacher (&mlp, ELOSS_FUNCTION_DEFAULT);

      std::vector<double> p0 = {0, 0};
      std::vector<double> p1 = {0, 1};
      std::vector<double> p2 = {1, 0};
      std::vector<double> p3 = {1, 1};

      std::vector<double> a0 = {0};
      std::vector<double> a1 = {0};
      std::vector<double> a2 = {0};
      std::vector<double> a3 = {1};

      std::vector< Signals > answers = {a0, a1, a2, a3};

      std::vector< Signals > patterns
       = {p0, p1, p2, p3};

       std::pair<int, float> *info = teacher.teach(patterns, answers, 0.1, 0.1, 7000, true);
       std::cout << "teached for " << info->first << " iterations; loss: " << info->second << std::endl;
       delete info;

      TS_ASSERT_DELTA(mlp.impulse (p0)[0], answers[0][0], 0.1);
      TS_ASSERT_DELTA(mlp.impulse (p1)[0], answers[1][0], 0.1);
      TS_ASSERT_DELTA(mlp.impulse (p2)[0], answers[2][0], 0.1);
      TS_ASSERT_DELTA(mlp.impulse (p3)[0], answers[3][0], 0.1);
    }
};
