//testPostfixCalc.cpp

#include "postfixCalculator.h"
#include <iostream>
#include <string>
#include <exception>

using namespace std;

int main() {

  int result;
  int intT;
  string stringT;
  string equation;
  vector<string> v;

  cout << "enter an equation in RPN form" << endl;
  getline(cin, equation);
  cout <<  equation << " = ";
  
  postfixCalculator calc;
  v = calc.toVector(equation);

  for(int i = 0; i < v.size(); i++){
    try{
      intT = stoi(v.at(i));
      calc.pushInt(intT);
    }
    catch(exception e){
      stringT = v.at(i);
      if(stringT == "+")
    	calc.add();
      if(stringT == "-")
    	calc.subtract();
      if(stringT == "*")
    	calc.multiply();
      if(stringT == "/")
    	calc.divide();
      if(stringT == "~")
    	calc.negation();
    }
  }
  
  result = calc.topInt();

  cout << result << endl;

  return 0;
}
