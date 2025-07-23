#include "../inc/RPN.hpp"

//std::stack<double> RPN::stack;

RPN::RPN()
{}

RPN::RPN(const RPN& other)
{
	(void)other;
}

RPN& RPN::operator=(const RPN& other)
{
	(void)other;
	return *this;
}

RPN::~RPN(){}

double RPN::get_num(std::stack<double>& stack)
{
	double result = stack.top();
	stack.pop();
	return result;
}

void RPN::evaluate(std::string input)
{
	std::stack<double> stack;
	for (size_t i = 0; i < input.size(); i++)
	{
		if (isspace(input[i]))
			continue;
		else if (isdigit(input[i]) /*&& stack.size() < 2*/)
			stack.push(input[i] - '0');
		// else if (isdigit(input[i]) && stack.size() == 2)
		// 	throw std::runtime_error("Error: expected operator.");
		else if (std::string("+-/*").find(input[i]) == std::string::npos)
			throw std::runtime_error(std::string("Error: unrecognized character: '")+ input[i] + "'");
		else if (std::string("+-/*").find(input[i]) != std::string::npos && stack.size() >= 2)
		{
			double result = get_num(stack);
			switch(input[i])
			{
				case '+':
					result = get_num(stack) + result;
					break;
				case '-':
					result = get_num(stack) - result;
					break;
				case '/':
					result = get_num(stack) / result;
					break;
				case '*':
					result = get_num(stack) * result;
					break;
			}
			stack.push(result);
		}
		else
		{
			throw std::runtime_error(std::string("Error: did not expect: '") + input[i] + "' here.");
		}
	}
	if (stack.size() > 1)
		throw std::runtime_error("Error: unexpected end to expression.");
	std::cout << get_num(stack) << std::endl;
}