//postfixCalculator.cpp

#include "postfixCalculator.h"
#include <sstream>

using namespace std;

postfixCalculator::postfixCalculator(){
  s = stack();
}

vector<string> postfixCalculator::toVector(string str){
  vector<string> v;
  stringstream ss(str);
  string t;
  char const *space = " ";

  while(getline(ss, t, *space)){
    v.push_back(t);
  }

  return v;
}

void postfixCalculator::pushInt(int n){
  s.push(n);
}

void postfixCalculator::popInt(){
  s.pop();
}

int postfixCalculator::topInt(){
  return s.top();
}


void postfixCalculator::add(){
  int oprand1 = topInt();
  popInt();
  int oprand2 = topInt();
  popInt();

  pushInt(oprand2 + oprand1);
}

void postfixCalculator::subtract(){
  int oprand1 = topInt();
  popInt();
  int oprand2 = topInt();
  popInt();

  pushInt(oprand2 - oprand1);
}

void postfixCalculator::multiply(){
  int oprand1 = topInt();
  popInt();
  int oprand2 = topInt();
  popInt();

  pushInt(oprand2 * oprand1);
}

void postfixCalculator::divide(){
  int oprand1 = topInt();
  popInt();
  int oprand2 = topInt();
  popInt();

  pushInt(oprand2 / oprand1);
}

void postfixCalculator::negation(){
  int oprand = topInt();
  popInt();

  pushInt(-1*oprand);

}
