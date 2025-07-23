#ifndef BITCOINEXCHANGE_H
#define BITCOINEXCHANGE_H

#include <iostream>
#include <map>
#include <fstream>
#include <stdexcept>
#include <cstdlib>

class BitcoinExchange {
public:
    BitcoinExchange();

    BitcoinExchange(const BitcoinExchange& other);

    BitcoinExchange& operator=(const BitcoinExchange& other);

	~BitcoinExchange();

	void init_map();

	std::map<std::string, double> get_database()const;

	void evaluate(std::string file);
private:
	std::map<std::string, double> database;
};

#endif // BITCOINEXCHANGE_H
