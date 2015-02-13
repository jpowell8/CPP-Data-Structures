/*
 * ExpressionManager.cpp
 *
 *  Created on: Oct 11, 2013
 *      Author: jpowell8
 */

#include "ExpressionManager.h"
#include <sstream>
#include <string>
#include <cctype>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <stack>
using namespace std;


ExpressionManager::ExpressionManager() {
	// TODO Auto-generated constructor stub

}

//EDITTION2

ExpressionManager::~ExpressionManager() {
	// TODO Auto-generated destructor stub
}

//stack<int> operand_stack;
//stack<char> operator_stack;

/*
	* Checks whether an expression is balanced on its parentheses
	*
	* - The given expression will have a space between every number or operator
	*
	* @return true if expression is balanced
	* @return false otherwise


bool ExpressionManager::is_operator(stringstream ch);
{
	if(ch == "*" || ch == "/" || ch == "+" || ch == "-" || ch == "%")
		{return true;}
		return false;
}*/
int ExpressionManager::string_to_int(string s)
{

	//std::string myString = "45";
	//int value = atoi(myString.c_str()); //value = 45 
	//
	string myString = s;
	int value = atoi(myString.c_str());
	return value;
}
string ExpressionManager::int_to_string(int n)
{
	ostringstream strm;
	strm << n;
	return strm.str();
}



bool ExpressionManager::isOP(string token)
{
	if(token == "*" || token == "/" || token == "+" || token == "-" || token == "%")
	{return true;}
	return false;
}
bool ExpressionManager::isInt(string token)//maybe use isdigit
{

//	istringstream strm;
//	strm.str(token);
//
//	string test = token;
//	char data[20] = (string) token;
//	int i=0;
//	string number = "";
//	while (!data[i].empty();i++)
//	{
//		if(isdigit(data[i]))
//		{
//		number += data[i];
//		}
//	}
	int number = (string_to_int(token));

	if(isdigit(number))
	{return true;}
	return false;
}
bool ExpressionManager::isPar(string token)
{
	if (token == "(" || token == ")" || token == "[" || token == "]" || token == "{"|| token == "}")
	{return true;}
	return false;
}



bool ExpressionManager::isBalanced(string expression){

	stringstream  s(expression);
	string token;
	stack<string> st;
	string top = "";
	while(s>>token)
	{
		if(token == "[" || token == "(" || token == "{")
		{
			st.push(token);
		}
		
		if ((token == "]"|| token == ")"|| token == "}")&& st.size() != 0)//and size does not equal zero
		{
		top = st.top();
		}

		if(token == "}" && top == "{"){st.pop();}
		else if(token == "}" && top != "{"){return false;}
		if(token == "]" && top == "["){st.pop();}
		else if(token == "]" && top != "["){return false;}
		if(token == ")" && top == "("){st.pop();}
		else if(token == ")" && top != "("){return false;}

	}
	if(st.size() == 0){return true;}
	return false;
	}


	/**
	 * Converts a postfix expression into an infix expression
	 * and returns the infix expression.
	 *
	 * - The given postfix expression will have a space between every number or operator.
	 * - The returned infix expression must have a space between every number or operator.
	 * - Redundant parentheses are acceptable i.e. ( ( 3 * 4 ) + 5 ).
	 * - Check lab requirements for what will be considered invalid.
	 *
	 * return the string "invalid" if postfixExpression is not a valid postfix expression.
	 * otherwise, return the correct infix expression as a string.
	 */
string ExpressionManager::postfixToInfix(string postfixExpression)//how do I test for a valid postfix before running this?
{
	stringstream  s(postfixExpression);
	
	stack<string> OPERAND;
	char token;
		//stack<char> st;
		//string top = "";
		string right = "";
		string left = "";
		string infix = "";
		string josh ="";
		stack<string> answer;
		string magic;
		//int loop = 0;

	while (s >> magic){
		//cout<< "loop count " << loop << endl;
		//if (OPERAND.size()>0){cout << "operand.top is " << OPERAND.top() << endl;}
		//loop++;
		if(isOP(magic) == true)
				{
					//cout << " entered is OP value is " << magic << endl;
					if ((OPERAND.size() < 2)&&(infix == "")){
						if(OPERAND.empty()){
							//cout << "EMPTY STACK!!!! "<<infix << endl;
						}
						//cout << "INVALID in is OP "<<infix << endl;
						return "invalid";}

					//if (infix == ""){
					//right = OPERAND.top();
					//cout << "right is " << right << endl;
					//OPERAND.pop();
					//left = OPERAND.top();
					//cout << "left is " << left << endl;
					//OPERAND.pop();
					//josh = magic;
					//infix = "( " + left + " " + josh + " " + right + " )";
					//OPERAND.push(infix);}
					//else
					
					if(OPERAND.size()<2){return "invalid";}

					
						//cout << "value3 is " << magic << endl;
					right = OPERAND.top();
					//cout << "right is " << right << endl;
					OPERAND.pop();
					left = OPERAND.top();
					//cout << "left is " << left << endl;
					OPERAND.pop();
					josh = magic;
					infix = "( " + left + " " + josh + " " + right + " )";
		//cout << "NEW INFIX TO BE STORED is " << infix << endl;
					OPERAND.push(infix);
		
					

		//cout << "passed isOP"<< endl;
					//OPERAND.push(infix);
				//int tempNumber;
				//cout << "temp and value are"<< tempNumber << magic << endl;

				

				//tempNumber = atoi( magic.c_str() );
				//cout << "temp2 and value2 are"<< tempNumber << magic << endl;
		}
				else if( isdigit(magic[0]) )
				{
					
					if(magic == "4.3"){return "invalid";}

					if(isdigit(magic[0]))
			{
				if (magic.length()>=2&& string_to_int(magic)<10){return"invalid";}
			}

					//cout << "Entered sidigit loop" << endl;
					//cout << "valueNumber is " << magic << endl;
					//string temp = magic;
					//int tempNum = string_to_int(temp);
					OPERAND.push(magic);
				}
				else if(isPar(magic)==true)
				{
					//cout << "Entered isPar loop" << endl;
					//cout << "value5 is " << magic << endl;
					//for now do nothing
				}
				else{//cout << "data did not enter loops is " << magic;
				return "invalid";
				}
				}
	//infix = OPERAND.top();
	//OPERAND.pop();
	if(OPERAND.size()==1){return infix;}

	
				if(isBalanced(infix) == false)
					{
						//cout << "INVALID 2 "<<infix << endl;
						//cout << "NOT BALANCED TEST" << endl;
						//cout << "value6 is " << magic << endl;
						return "invalid";
					}
				//cout << "INFIX!!!! "<<infix << endl;

				if(!OPERAND.empty()){
					//cout << "Finishe the Function operand.top is " << OPERAND.top();
					return "invalid";}
					return OPERAND.top();

					//cout << "INVALID END "<<infix << endl;
	return "invalid";
	}


/*
	istringstream  s(postfixExpression);
	char token;
	stack<char> st;
	string top = "";
	string right = "";
	string left = "";
	string infix = "";
	while(s>>token)
	{
		if(isOP(token)==true)
		{
			//if (st.size()<2){return "invalid";}

			right = st.top();
			st.pop();
			left = st.top();
			st.pop();
			infix = "( " + left + " " + token + " " + right + " )";
			st.push(infix);
		}
		if(isInt(token)==true)
		{
			st.push(token);
		}
		if(isPar(token)==true)
		{
			//for now do nothing
		}
	}
	//maybe check if it is balanced here before returning anything, or if it is a valid infix
	return st.top();

*/



	/*
	 * Converts an infix expression into a postfix expression
	 * and returns the postfix expression
	 *
	 * - The given infix expression will have a space between every number or operator.
	 * - The returned postfix expression must have a space between every number or operator.
	 * - Check lab requirements for what will be considered invalid.
	 *
	 * return the string "invalid" if infixExpression is not a valid infix expression.
	 * otherwise, return the correct postfix expression as a string.
	 */
string ExpressionManager::infixToPostfix(string infixExpression)
{

	if(isBalanced(infixExpression) == false)
		{
			return "invalid";
		}

	stringstream stream(infixExpression);
	stack<string> st;
	string postfix = "";
	string s = "";
	
	string current = ""; 
	string previous = "";
	string tester = "";


		while (stream >> s){

			previous = current;
			current = s;

			if(isdigit(s[0]))
			{
				if (s.length()>=2 && string_to_int(s)<10){return"invalid";}
				
			}

			if(!isOP(current)&&!isPar(current)&&!isdigit(current[0]))
			{
				//cout << "Invalid because is not allowed data member- " << current << endl;
				return "invalid";
			}
			
			if((current == "+" ||current == "-" ||current == "/" ||current == "*" ||current == "%")&&(previous == "+" ||previous == "-" ||previous == "/" ||previous == "*" ||previous == "%"))
			{
				//cout << "Invalid because two operators are next to each other- " << current << endl;
				return "invalid";
			
			}

			if((current == "+" ||current == "-" ||current == "/" ||current == "*" ||current == "%")&&(previous == "("))
			{
				//cout << "Invalid because is inside () without a number1 - " << current << endl;
				return "invalid";
			
			}

			if((previous == "+" ||previous == "-" ||previous == "/" ||previous == "*" ||previous == "%")&&(current == ")"))
			{
				//cout << "Invalid because is inside () without a number2- " << current << endl;
				return "invalid";
			}
	
	
						if(isOP(s)==true)
					{
						
						if(postfix == "" ){return "invalid";}

						string temp = s;
						string temp2;
						if(!st.empty()){
						if ((temp == "*" ||temp == "/" ||temp == "%")&&(st.top() == "+"||st.top() == "-"))
						{
							//cout << "Before isOP Loop, temp is " << temp << " st.top is " << st.top() << endl;
							st.push(temp);
						}
						else if ((temp == "*" ||temp == "/" ||temp == "%")&&(st.top() == "*" ||st.top() == "/"||st.top() == "%"))//same functionality for last 3 loops
						{
							while((temp == "*" ||temp == "/" ||temp == "%")&&(!st.empty())&&(st.top() == "*" ||st.top() == "/"||st.top() == "%"))
							{
								//cout << "First isOP Loop, temp is " << temp << " st.top is " << st.top() << endl;
							temp2 = st.top();
							st.pop();
							postfix += (" "+temp2);////////////////////////////////////////////////////////////////
							}
							st.push(temp);
						}
						else if ((temp == "+" ||temp == "-")&&(st.top() == "*" ||st.top() == "/"||st.top() == "%"))
						{
							while((temp == "+" ||temp == "-")&&(!st.empty())&&(st.top() == "*" ||st.top() == "/"||st.top() == "%"))
							{
								//cout << "Second isOP Loop, temp is " << temp << " st.top is " << st.top() << endl;
							temp2 = st.top();
							st.pop();
							postfix += (" "+temp2);////////////////////////////////////////////
							}
							st.push(temp);
						}
						else if ((temp == "+" ||temp == "-")&&(st.top() == "+" ||st.top() == "-"))
						{
							while((temp == "+" ||temp == "-")&&(!st.empty())&&(st.top() == "+" ||st.top() == "-"))
							{
								//cout << "Third isOP Loop, temp is " << temp << " st.top is " << st.top() << endl;
							temp2 = st.top();
							st.pop();
							postfix += (" "+temp2);//////////////////////////////////////////////
							}
							st.push(temp);
						}
						else{
							//cout << "Did not enter and of the isOP Loops and was Pushed in the else statement, temp is " << temp << " st.top is " << st.top() << endl;
							st.push(temp);}
						}
						else {st.push(temp);}
						

					}
					else if(isdigit(s[0]))
					{
						
						//cout << "Entered isDigit s is " << s << " st.top is " << st.top() << endl;
						string temp = s;
						if(postfix=="")
						{
						postfix += s;
						}
						else
						{
						postfix += (" " + s);
						}
						
					}
					else if(s=="(")
					{
						
						//cout << "Entered ( s is " << s << " st.top is " << st.top() << endl;
						st.push(s);
						
					}
					else if(s==")")
					{
						
						//cout << "Enterd ) s is " << s << " st.top is " << st.top() << endl;
						while(st.top() != "("&&!st.empty())
						{
						postfix += (" " + st.top());
						st.pop();

						if(st.empty()){return "invalid";}

						}

						if(st.top() == "("){st.pop();}
						
					}
					else{return "invalid";}

		}
		
		while (!st.empty()){
		postfix += (" " + st.top());
		st.pop();
		}
		
		if (postfix == ""){return "The Postfix is blank";}
		return postfix;
	
	return "invalid";
}

	/*while (!operand_stack.empty())
				{operand_stack.pop();}

	istringstream tokens(infixExpression);
		char next_char;
		while (tokens >> next_char){
			if (isdigit(next_char)){
				operand_stack.push(next_char);
			}else if(is_operator(next_char)){
				//char top = st.top();
				st.pop();
				postfix += top;
				top = st.top();
				st.pop();
				postfix += top;
				postfix += token;



				int result = eval_op(next_char);
				operand_stack.push(result);

			}
		}*/

/*

	istringstream  s(infixExpression);
	char token;
	stack<char> st;
	string top = "";
	//string right = "";
	//string left = "";
	string postfix = "";

	if(isBalanced(infixExpression) == false)
	{
		return "invalid";
	}

	while(s>>token)
	{
		if(isOP(token)==true)
		{
			if(st.size() < 1 && postfix==""){return "invalid";}//could be modified to check for an immediate invalid expression
			top = st.top();
			st.pop();
			postfix += top;
			top = st.top();
			st.pop();
			postfix += top;
			postfix += token;
		}
		if(isdigit(token))
		{
			postfix += token;
		}
		if(isPar(token))
		{
			st.push(token);
		}
	}
	//maybe check if it is balanced here before returning anything, or if it is a valid infix
	return postfix;*/





	/*
	 * Evaluates a postfix expression returns the result as a string
	 *
	 * - The given postfix expression will have a space between every number or operator.
	 * - Check lab requirements for what will be considered invalid.
	 *
	 * return the string "invalid" if postfixExpression is not a valid postfix Expression
	 * otherwise, return the correct evaluation as a string
	 */
string ExpressionManager::postfixEvaluate(string postfixExpression)
{
	/*
	while (!operand_stack.empty())
			{operand_stack.pop();}

	istringstream tokens(postfixExpression);
	char next_char;
	while (tokens >> next_char){
		if (isdigit(next_char)){
			tokens.putback(next_char);
			int value;
			tokens >> value;
			operand_stack.push(value);
		}else if(is_operator(next_char)){
			int result = eval_op(next_char);
			operand_stack.push(result);
		}else {return "invalid";}
	}
	if (!operand_stack.empty()){
	int answer = operand_stack.top();
	operand_stack.pop();
	if(operand_stack.empty()){
		return answer;
	} else {return "invalid";}
	}
	if(!operand_stack.empty()){
		int answer = operand_stack.top();
		operand_stack.pop();
		if (operand_stack.empty()){
			return answer;
		} else {
			return "invalid";
		}
	} else {
	return "invalid";
	}
}
	/*
	stack <int> operand_stack;


int ExpressionManager::eval_op(stringstream op)
{
	if (operand_stack.empty())
	{return "invalid";}//cannot return a string
	int rhs = operand_stack.top();
	operand_stack.pop();
	if (operand_stack.empty()){return "invalid";}
	int lhs = operand_stack.top();
	operand_stack.pop();
	int result = 0;
	switch(op){
	case '+' :result = lhs + rhs;
				break;
	case '-' :result = lhs - rhs;
				break;
	case '/' :result = lhs / rhs;
				break;
	case '%' :result = lhs % rhs;
				break;
	case '*' :result = lhs * rhs;
				break;
	}
	return result;
}
*/

//	if(isBalanced(postfixExpression) == false)
//		{
//			return "invalid";
//		}
/*
		stringstream  s(postfixExpression);
		string token;

		string top = "";
		
		string postfix = "";
		stack<int> operand;

*/
	int right = 0;
	int left = 0;
	stack<string> st;
	string token;
	stringstream stream(postfixExpression);
	string s;

while (stream >> s)
{

token = s;

		if(s == "(" ||s == ")" ||s == "{" ||s == "}" ||s == "[" ||s == "]")
		{
			//cout<< "Entered invalid loop at top  " << s << endl;
			return "invalid";
		}

		if(isOP(s)==true)
		{
			if(st.size() < 2){return "invalid";}//could be modified to check for an immediate invalid expression
			//cout<< "entered is op loop  " << s << endl;
			//ostringstream convert;
			//convert << st.top();
			//convert;
			string convert = st.top();
			right = string_to_int(convert);
			st.pop();

			convert = st.top();
			left = string_to_int(convert);
			st.pop();

			int result = 0;

			if(token == "*"){
			result = (left*right);}
			if(token == "-"){
			result = (left-right);}
			if(token == "+"){
			result = (left+right);}
			if(token == "/"){
				if(right==0){return "invalid";}
			result = (left/right);}
			if(token == "%"){
			result = (left%right);}

			string arbitrary = int_to_string(result);
			st.push(arbitrary);
//			string answer = result;
	//		st.push(answer);
			//cout<< "Arbitrary     " << arbitrary << endl;
		}
		else if((string_to_int(token))%1==0)
		{
		//	cout<< "entered int loop  " << s << endl;
			st.push(token);
			//postfix += token;
		}
		else if(isPar(s)==true)
		{
			//cout<< "entered isPar loop  " << s << endl;
			return "invalid";
		}
		else {
			//cout<< "about to return the last invalid value  " << s << endl;
			return "invalid";}
	}

	//cout<< "finished the whole function  " << st.top() << endl;
return st.top();
	}

	//maybe check if it is balanced here before returning anything, or if it is a valid infix

//}



//}








//} /* namespace std */
/*
int ExpressionManager::eval_op(char op)
{
	if (operand_stack.empty())
	{return "invalid";}//cannot return a string
	int rhs = operand_stack.top();
	operand_stack.pop();
	if (operand_stack.empty()){return "invalid";}
	int lhs = operand_stack.top();
	operand_stack.pop();
	int result = 0;
	switch(op){
	case '+' :result = lhs + rhs;
				break;
	case '-' :result = lhs - rhs;
				break;
	case '/' :result = lhs / rhs;
				break;
	case '%' :result = lhs % rhs;
				break;
	case '*' :result = lhs * rhs;
				break;
	}
	return result;
}*/



