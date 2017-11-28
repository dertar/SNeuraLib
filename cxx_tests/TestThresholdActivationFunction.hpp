#include <cxxtest/TestSuite.h>
#include "../src/ActivationFunctions/ThresholdActivationFunction.hpp"

class TestThresholdActivationFunction :  public CxxTest::TestSuite
{
private:

public:
    void testFunction(void)
    {
      ThresholdActivationFunction func (0.5);

      TS_ASSERT(func.function (0.1) == 0.1);
      TS_ASSERT(func.function (0.7) == 0.7);
      TS_ASSERT(func.function (0.5) == 0.5)

      TS_ASSERT(func.isActive (0.1) == false);
      TS_ASSERT(func.isActive (0.7) == true);
      TS_ASSERT(func.isActive (0.5) == true);
    }
};
