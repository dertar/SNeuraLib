#include <cxxtest/TestSuite.h>
#include "../src/SingleLayerPerceptron.hpp"
#include "../src/ActivationFunctions.hpp"
#include "Utils.cpp"
#include "../src/Learnings/StochasticGradientLearning.hpp"
#include "../src/LossFunctions/SquareLossFunction.hpp"
#include <iostream>

class TestErrorStochasticGradientLearning : public CxxTest::TestSuite
{
public:
    void testTeachErrorCorrection(void)
    {
      SingleLayerPerceptron slp(2, 1, new SigmoidActivationFunction ());
      StochasticGradientLearning teacher (&slp, new SquareLossFunction ());

      std::vector<double> p3 = {1, 1};

      std::vector<double> a1 = {1};

      std::vector< Signals > answers = {a1};

      std::vector< Signals > patterns
       = {p3};

      int iterations = teacher.teach(patterns, answers, 0.1, 0.1, 50);

      TS_ASSERT_DELTA(slp.impulse(p3)[0], answers[0][0], 0.1);
    }

    void testTeachErrorCorrectionAND0(void)
    {
      SingleLayerPerceptron slp(2, 1, new SigmoidActivationFunction ());
      StochasticGradientLearning teacher (&slp, new SquareLossFunction ());

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

      int iterations = teacher.teach(patterns, answers, 0.1, 0.1, 50);

        TS_ASSERT_DELTA(slp.impulse (p0)[0], answers[0][0], 0.1);

      TS_ASSERT_DELTA(slp.impulse (p1)[0], answers[1][0], 0.1);

      TS_ASSERT_DELTA(slp.impulse (p2)[0], answers[2][0], 0.1);

      TS_ASSERT_DELTA(slp.impulse (p3)[0], answers[3][0], 0.1);
    }

    void testTeachErrorCorrectionOR0(void)
    {
      SingleLayerPerceptron slp(2, 1, new SigmoidActivationFunction ());
      StochasticGradientLearning teacher (&slp, new SquareLossFunction ());

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

      int iterations = teacher.teach(patterns, answers, 0.1, 0.1, 50);

      TS_ASSERT_DELTA(slp.impulse (p0)[0], answers[0][0], 0.1);

      TS_ASSERT_DELTA(slp.impulse (p1)[0], answers[1][0], 0.1);

      TS_ASSERT_DELTA(slp.impulse (p2)[0], answers[2][0], 0.1);

      TS_ASSERT_DELTA(slp.impulse (p3)[0], answers[3][0], 0.1);


    }

    void testTeachErrorCorrectionNegative0(void)
    {
      SingleLayerPerceptron slp(1, 1, new SigmoidActivationFunction ());
      StochasticGradientLearning teacher (&slp, new SquareLossFunction ());

      std::vector<double> p0 = {0};
      std::vector<double> p1 = {1};

      std::vector<double> a0 = {1};
      std::vector<double> a1 = {0};

      std::vector< Signals > answers = {a0, a1};

      std::vector< Signals > patterns
          = {p0, p1};

      int iterations = teacher.teach(patterns, answers, 0.1, 0.1, 50);

      TS_ASSERT_DELTA(slp.impulse (p0)[0], answers[0][0], 0.1);
      TS_ASSERT_DELTA(slp.impulse (p1)[0], answers[1][0], 0.1);
    }

    void testTeachErrorCorrectionAND1(void)
    {
      SingleLayerPerceptron slp(2, 2, new SigmoidActivationFunction ());
      StochasticGradientLearning teacher (&slp, new SquareLossFunction ());

      std::vector<double> p0 = {0, 0};
      std::vector<double> p1 = {0, 1};
      std::vector<double> p2 = {1, 0};
      std::vector<double> p3 = {1, 1};

      std::vector<double> a0 = {1,0};
      std::vector<double> a1 = {1,0};
      std::vector<double> a2 = {1,0};
      std::vector<double> a3 = {0,1};

      std::vector< Signals > answers = {a0, a1, a2, a3};

      std::vector< Signals > patterns
          = {p0, p1, p2, p3};

      int iterations = teacher.teach(patterns, answers, 0.1, 0.1, 50);

      TS_ASSERT_DELTA(slp.impulse (p0)[0], answers[0][0], 0.1);
      TS_ASSERT_DELTA(slp.impulse (p0)[1], answers[0][1], 0.1);

      TS_ASSERT_DELTA(slp.impulse (p1)[0], answers[1][0], 0.1);
      TS_ASSERT_DELTA(slp.impulse (p1)[1], answers[1][1], 0.1);

      TS_ASSERT_DELTA(slp.impulse (p2)[0], answers[2][0], 0.1);
      TS_ASSERT_DELTA(slp.impulse (p2)[1], answers[2][1], 0.1);

      TS_ASSERT_DELTA(slp.impulse (p3)[0], answers[3][0], 0.1);
      TS_ASSERT_DELTA(slp.impulse (p3)[1], answers[3][1], 0.1);
    }

};
