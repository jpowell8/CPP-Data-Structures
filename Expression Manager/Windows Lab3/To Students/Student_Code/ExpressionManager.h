#include "ExpressionManagerInterface.h"
#ifndef EXPRESSIONMANAGER_H_
#define EXPRESSIONMANAGER_H_
#include <iostream>

#include <sstream>
#include <locale>
#include <stack>
#include <string>
#include <locale>
#include <cctype>


using namespace std;

class ExpressionManager : public ExpressionManagerInterface
{
public:
	ExpressionManager();
	virtual ~ExpressionManager();

	int string_to_int(string s);
	string int_to_string(int n);

	bool isOP(string token);
	bool isInt(string token);
	bool isPar(string token);

	bool is_operator(stringstream ch);


	bool isBalanced(string expression);

	string postfixToInfix(string postfixExpression);

	string infixToPostfix(string infixExpression);

	string postfixEvaluate(string postfixExpression);

private:

int eval_op(char op);


};

 /* namespace std */
#endif /* EXPRESSIONMANAGER_H_ */
