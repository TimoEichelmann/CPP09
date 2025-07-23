#ifndef RPN_HPP
#define RPN_HPP
#include <stack>
#include <iostream>
#include <stdexcept>

class RPN
{
	public:
		static void evaluate(std::string input);
		static double get_num(std::stack<double>& stack);
	private:
		//static std::stack<double> stack;
		RPN();
		RPN(const RPN& other);
		RPN& operator=(const RPN& other);
		~RPN();
};

#endif