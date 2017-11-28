#include <cxxtest/TestSuite.h>
#include "../src/ActivationFunctions/SigmoidActivationFunction.hpp"

class TestSigmoidActivationFunction : public CxxTest::TestSuite
{
private:

public:
    void testFunction(void)
    {
      SigmoidActivationFunction func (0.5);

      TS_ASSERT_DELTA (func.function (0.1), 0.52, 0.01);
      TS_ASSERT_DELTA (func.function (0), 0.5, 0.01);
      TS_ASSERT_DELTA (func.function (1), 0.73, 0.01);

    }

};
