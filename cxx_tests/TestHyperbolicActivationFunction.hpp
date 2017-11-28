#include <cxxtest/TestSuite.h>
#include "../src/ActivationFunctions/HyperbolicActivationFunction.hpp"

class TestHyperbolicActivationFunction : public CxxTest::TestSuite
{
private:

public:
    void testFunction(void)
    {
      HyperbolicActivationFunction func (0.5);

      TS_ASSERT_DELTA (func.function (0.1), 0.099, 0.001);
      TS_ASSERT_DELTA (func.function (0), 0, 0.01);
      TS_ASSERT_DELTA (func.function (1), 0.76, 0.01);

    }

};
