#include <cxxtest/TestSuite.h>
#include "../src/ActivationFunctions/LinearActivationFunction.hpp"

class TestLinearActivationFunction : public CxxTest::TestSuite
{
private:

public:
    void testFunction0(void)
    {
      LinearActivationFunction func (0.5);

      TS_ASSERT(func.function (0.1) == 0.1);
      TS_ASSERT(func.function (0.7) == 0.7);
      TS_ASSERT(func.function (0.5) == 0.5)

      TS_ASSERT(func.isActive (0.1) == false);
      TS_ASSERT(func.isActive (0.7) == true);
      TS_ASSERT(func.isActive (0.5) == true);
    }

    void testFunction1(void)
    {
      LinearActivationFunction func (0.5, 2, 1);

      TS_ASSERT_DELTA(func.function (0.1), 1.2, 0.1);
      TS_ASSERT_DELTA(func.function (0.7), 2.4, 0.1);
      TS_ASSERT_DELTA(func.function (0.5), 2.0, 0.1)
    }
};
