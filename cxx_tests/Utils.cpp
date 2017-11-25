#ifndef _UTILS_CPP_
#define _UTILS_CPP_

#include <vector>

class Utils
{
public:

  static double Sum(const std::vector<double> &v)
  {
    double sum = 0.0;

    for(int i = 0; i < v.size(); i++)
    {
      sum += v[i];
    }

    return sum;
  }

};

#endif
