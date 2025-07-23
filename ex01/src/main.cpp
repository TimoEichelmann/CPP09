#include "../inc/RPN.hpp"

int main(int argc, char *argv[])
{
	if (argc != 2)
	{
		std::cerr << "Error: provide one argument." << std::endl;
		return (1);
	}
	try
	{
		RPN::evaluate(argv[1]);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
		return 1;
	}
	return (0);
}