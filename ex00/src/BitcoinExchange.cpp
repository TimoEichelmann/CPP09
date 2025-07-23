#include "../inc/BitcoinExchange.h"
    
BitcoinExchange::BitcoinExchange()
{
	//Default Constructor
	try
	{
		/* code */
		init_map();
	}
	catch(const std::exception& e)
	{
		throw std::runtime_error(e.what());
	}
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& other)
{
	//Copy Constructor
	database = other.get_database();
}
BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& other)
{
	//Copy Assignment Constructor
	database = other.get_database();
	return *this;
}
BitcoinExchange::~BitcoinExchange()
{
	//Dstructor
}

std::map<std::string, double> BitcoinExchange::get_database() const
{
	return this->database;
}

void BitcoinExchange::init_map()
{
	std::ifstream in("data.csv");
	if (!in.is_open())
		throw std::runtime_error("No Data File present.");
	std::string line;

	while(std::getline(in, line))
	{
		size_t pos = line.find(",");
		this->database.insert(std::pair<std::string, double>(line.substr(0, pos), atof((line.substr(pos + 1)).c_str())));
	}
}

bool check_date(std::string date)
{
	size_t pos1 = date.find("-");
	size_t pos2 = date.find("-", pos1 + 1);
	if (pos1 == std::string::npos || pos2 == std::string::npos)
		return false;
	if (pos1 != 4 || pos2 != 7)
		return false;
	if (date.substr(pos1 + 1, pos2 - pos1 - 1) > "12" || date.substr(pos2 + 1) > "31")
		return false;
	if (date.find_first_not_of("0123456789-") != std::string::npos)
		return false;
	return true;
}

bool check_amount(std::string amount)
{
	if (amount.find("-") != std::string::npos)
	{
		std::cout << "Error: not a positive number => " << amount << std::endl;
		return false;
	}
	if (amount.find_first_not_of("0123456789.") != std::string::npos)
	{
		std::cout << "Error: non numeric values => " << amount << std::endl;
		return false;
	}
	double f = atof(amount.c_str());
	if (f > 1000.0)
	{
		std::cout << "Error: too large number => " << amount << std::endl;
		return false;
	}
	return true;
}

void BitcoinExchange::evaluate(std::string file)
{
	std::ifstream in(file.c_str());
	if (!in.is_open())
		throw std::runtime_error("Error: could not open file");
	std::string line;
	std::getline(in, line);
	if (line != "date | value")
	{
		std::cout << "Error: File doesn't contain 'date | value' header" << std::endl;
		return ;
	}
	while (std::getline(in, line))
	{
		size_t pos = line.find("|");
		if (pos == std::string::npos)
		{
			std::cout << "Error: bad date => " << line << std::endl;
			continue;
		}
		std::string date = line.substr(0, pos - 1);
		if (!check_date(date))
		{
			std::cout << "Error: bad date => " << date << std::endl;
			continue;
		}
		std::string str_amount = line.substr(pos + 2).c_str();
		if (!check_amount(str_amount))
			continue;
		double amount = atof(str_amount.c_str());
		std::map<std::string, double>::iterator it = database.lower_bound(date);
		if (it != database.begin())
		{
			if (it == database.end() || it->first != date)
				--it;
		}
		std::cout << it->first << " => " << amount << " = " << amount * it->second << std::endl;
	}
}
