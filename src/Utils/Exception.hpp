#ifndef _EXCEPTION_HPP_
#define _EXCEPTION_HPP_

#include <exception>
#include <string>

class Exception : public std::exception
{
private:
  std::string msg;
public:
  Exception(std::string& msg);
  Exception(const char* msg);

  virtual const char* what() const throw();
};

#endif
