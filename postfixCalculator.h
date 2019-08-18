//postfixCalculator.h

#ifndef POSTFIX_CALCULATOR_H
#define POSTFIX_CALCULATOR_H

#include "stack.h"
#include <vector>
#include <string>

class postfixCalculator {
  
 public:
  postfixCalculator();
  std::vector<std::string> toVector(std::string s);
  void pushInt(int n);
  void popInt();
  int topInt();
  void add();
  void subtract();
  void multiply();
  void divide();
  void negation();
  
 private:
  stack s;
  
};

#endif
