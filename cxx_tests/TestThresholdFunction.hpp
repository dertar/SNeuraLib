#include <cxxtest/TestSuite.h>
#include "../src/ActivationFunction.hpp"

#include <iostream>

class TestThresholdFunction : public CxxTest::TestSuite
{
private:

public:
    void testFunction(void)
    {
      ThresholdFunction func (0.5);

      TS_ASSERT(func.isActive (0.1) == false);
      TS_ASSERT(func.isActive (0.7) == true);
      TS_ASSERT(func.isActive (0.5) == true);
    }
};
