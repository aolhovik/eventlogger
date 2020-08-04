
#ifndef STACKTRACER_H_
#define STACKTRACER_H_

#include <string>
#include <iostream>

/// RAII over simple output
struct Stacktracer
{
  Stacktracer(const std::string &Blockname, std::ostream &out= std::cout);
  ~Stacktracer();

  std::string _Blockname;
  std::ostream &_out;
};

#endif /* STACKTRACER_H_ */
