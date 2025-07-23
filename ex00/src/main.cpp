#include "../inc/BitcoinExchange.h"

int main (int argc, char *argv[])
{
	if (argc != 2)
	{
		std::cerr << "Error: Please input 1 file to evaluate." << std::endl;
		return 1;
	}
	try
	{
		BitcoinExchange exch;
		exch.evaluate(argv[1]);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	return 0;
}