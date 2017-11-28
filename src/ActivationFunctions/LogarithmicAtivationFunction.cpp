#include "LogarithmicAtivationFunction.hpp"

LogarithmicAtivationFunction::LogarithmicAtivationFunction (double threshold)
  : ActivationFunction (threshold)
{

}

double LogarithmicAtivationFunction::function (double x)
{
  return log (x + sqrt (x*x + 1));
}
