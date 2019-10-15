#ifndef __CALCULATOR__
#define __CALCULATOR__

#include <string>
#include "Stack.h"

using namespace std;

class Calculator {
public:
	Calculator(string);
	~Calculator();
	string getPostfix();
	int calculate();
	
private:
	Stack *stack;
	string postfixExpression;
	string infixExpression;

	int operate(int n1, int n2, char op);
	int getOperatorWeight(char op);
	bool isHigherPrecedence(char op1, char op2);
	bool isOperator(char c);
	bool isOperand(char c);
};

 #endif