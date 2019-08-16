//stack.cpp

#include "stack.h"
#include "ListItr.h"
#include <cstdlib>

using namespace std;

stack::stack(){
  list = List();
}

void stack::push(int n){
  ListItr pos = list.first();
  list.insertBefore(n, pos);
}

void stack::pop(){
  if(!empty())
    list.remove(top());
  else
    exit(-1);
}

int stack::top(){
  if(!empty()){
    ListItr pos = list.first();
    int x = pos.retrieve();
    return x;
  }
  else
    exit(-1);
}

bool stack::empty(){
  if(list.isEmpty())
    return true;
  return false;
}
