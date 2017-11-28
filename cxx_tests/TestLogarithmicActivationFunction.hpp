#include <cxxtest/TestSuite.h>
#include "../src/ActivationFunctions/LogarithmicAtivationFunction.hpp"

class TestLogarithmicActivationFunction : public CxxTest::TestSuite
{
private:

public:
    void testFunction(void)
    {
      LogarithmicAtivationFunction func (0.5);

      TS_ASSERT_DELTA (func.function (0.1), 0.099, 0.001);
      TS_ASSERT_DELTA (func.function (0.33), 0.32, 0.01);
      TS_ASSERT_DELTA (func.function (1.5), 1.19, 0.01);

    }

};
