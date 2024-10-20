#include "RPN.hpp"
#include <sstream>
#include <cctype>
#include <iostream>

RPN::RPN() {}

RPN::~RPN() {}

bool RPN::isOperator(char c)
{
	return (c == '+' || c == '-' || c == '*' || c == '/');
}

int RPN::performOperation(int a, int b, char op)
{
	switch (op)
	{
	case '+':
		return a + b;
	case '-':
		return a - b;
	case '*':
		return a * b;
	case '/':
		if (b == 0)
		{
			throw std::runtime_error("Division by zero");
		}
		return a / b;
	default:
		throw std::runtime_error("Invalid operator");
	}
}


int RPN::evaluate(const std::string &expression)
{
	std::stack<int> stack;
	std::istringstream iss(expression);
	std::string token;
	
	while (iss >> token)
	{
		if (token.size() == 1 && isOperator(token[0]))
		{
			if (stack.size() < 2)
			{
				throw std::runtime_error("Invalid expression");
			}
			int b = stack.top();
			stack.pop();
			int a = stack.top();
			stack.pop();
			int result = performOperation(a, b, token[0]);
			stack.push(result);
		}
		else if (isdigit(token[0]))
		{
			stack.push(token[0] - '0');
		}
		else
		{
			throw std::runtime_error("Invalid character in expression");
		}
	}

	if (stack.size() != 1)
	{
		throw std::runtime_error("Invalid expression");
	}

	return stack.top();
}
