#include <cxxtest/TestSuite.h>
#include "../src/ActivationFunctions/GaussianActivationFunction.hpp"

class TestGaussianActivationFunction : public CxxTest::TestSuite
{
private:

public:
    void testFunction(void)
    {
      GaussianActivationFunction func (0.5);

      TS_ASSERT_DELTA (func.function (0.0), 1, 0.001);
      TS_ASSERT_DELTA (func.function (0.1), 0.99, 0.01);
      TS_ASSERT_DELTA (func.function (1.5), 0.32, 0.01);
      TS_ASSERT_DELTA (func.function (0.56), 0.85, 0.01)
    }

};
