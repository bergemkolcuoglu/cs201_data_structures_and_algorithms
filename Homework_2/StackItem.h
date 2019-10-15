#ifndef __STACKITEM__
#define __STACKITEM__

#include <iostream>
#include <sstream>
#include <string>

using namespace std;

// constant definitions for operator types
#define OPERATOR_MINUS			0
#define OPERATOR_PLUS			1
#define OPERATOR_DIVISION		2
#define OPERATOR_MULTIPLICATION 3
#define OPERATOR_LEFTPAR		4
#define OPERATOR_RIGHTPAR		5

class StackItem {

public:
	bool isOperator;
	int op;
	int n;
	StackItem *next;
	
	StackItem(bool, int);
	StackItem(string);
	
	string toString();
private:
	void init(bool, int);
};

#endif