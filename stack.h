//stack.h

#ifndef STACK_H
#define STACK_H

#include "List.h"

class stack {

 public:
  stack();
  void push(int n);
  void pop();
  int top();
  bool empty();

 private:
  List list;
};

#endif
