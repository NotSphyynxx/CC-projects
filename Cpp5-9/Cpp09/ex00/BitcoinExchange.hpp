#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <iostream>
#include <map>
#include <stdlib.h>

class BitcoinExchange {

    private:
    public:
    std::map<std::string, double> db;

    // BitcoinExchange();
    // BitcoinExchange(const BitcoinExchange &obj);
    // ~BitcoinExchange();
    // BitcoinExchange &operator=(const BitcoinExchange &obj);

    bool isValidDate(std::string &date);
    bool isValidValue(std::string &bitc, double &final_value) const;

    // int getExchangeRate(std::string &date) const;

    void    loadDatabase(const std::string &filename);
    void    parseInput(const std::string &filename);

};

#endif