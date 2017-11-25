#include "Exception.hpp"

Exception::Exception(std::string& msg)
{
  this->msg = msg;
}

Exception::Exception(const char* msg)
{
  this->msg = std::string(msg);
}

const char* Exception::what() const throw()
{
  return msg.c_str();
}
