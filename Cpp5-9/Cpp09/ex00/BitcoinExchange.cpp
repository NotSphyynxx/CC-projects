#include "BitcoinExchange.hpp"
#include <fstream>
#include <cstdlib>
#include <iterator>
#include <map>

void BitcoinExchange::loadDatabase(const std::string &filename){
    std::ifstream file(filename.c_str());
    if (!file.is_open()){
        std::cout << "Error opening file\n";
        return ;
    }
    std::string line;
    std::getline(file, line);

    while (getline(file, line)){
        size_t comma_pos = line.find(',', 0);
        if (comma_pos == std::string::npos){
            std::cout << "Parsing Error\n";
            return ;
        }
        std::string date = line.substr(0, comma_pos);
        std::string rate = line.substr(comma_pos + 1);

        char *endPtr;
        double Brate = std::strtod(rate.c_str(), &endPtr);
        db[date] = Brate;
    }
    file.close();
}

void BitcoinExchange::parseInput(const std::string &filename){
    std::ifstream file(filename.c_str());
    if (!file.is_open()){
        std::cout << "Error opening file\n";
        return ;       
    }
    std::string line;
    std::getline(file, line);
    while (getline(file, line)){
        size_t pipePos = line.find('|');
        if (pipePos == std::string::npos){
            std::cout << "Parsing Error\n";
            continue ;            
        }
        std::string date = line.substr(0, pipePos-1);
        std::string bitc = line.substr(pipePos + 2);

        if (!isValidDate(date)){
            std::cout << "Date Error => " << date << "\n";
            continue;       
        }
        double bitcoin;
        if (!isValidValue(bitc, bitcoin)){
            std::cout << "Value Error => " << bitc << "\n";
            continue;
        }
        double rate = getExchangeRate(date);
        if (rate == -1.0){
            std::cout << "Rate Error\n";
            continue ; 
        }
        double res = bitcoin * rate;
        std::cout << date << " ==> " << bitcoin << " = " << res << std::endl;
    }
}

bool BitcoinExchange::isValidValue(std::string &bitc, double &finnal_value) const {
    char *endPtr;

    finnal_value = std::strtod(bitc.c_str(), &endPtr);
    while (*endPtr != '\0' && isspace(*endPtr)) {
        endPtr++;
    }
    if (bitc.empty() || *endPtr != '\0')
        return false;
    if (finnal_value < 0)
        return false;
    if (finnal_value > 1000)
        return false;
    return true;
}


bool BitcoinExchange::isValidDate(std::string &date) const {
    if (date.length() != 10 || date[4] != '-' || date[7] != '-')
        return false;
    std::string yearstr = date.substr(0, 4);
    std::string monthstr = date.substr(5, 2);
    std::string daystr = date.substr(8, 2);

    for (size_t i = 0; i < yearstr.length(); i++) if (!isdigit(yearstr[i])) return false;
    for (size_t i = 0; i < monthstr.length(); i++) if (!isdigit(monthstr[i])) return false;
    for (size_t i = 0; i < daystr.length(); i++) if (!isdigit(daystr[i])) return false;

    int year = atoi(yearstr.c_str());
    int month = atoi(monthstr.c_str());
    int day = atoi(daystr.c_str());

    if (month < 1 || month > 12)
        return false;
    if (day < 1 || day > 31)
        return false;
    
    if (month == 4 || month == 6 || month == 9 || month == 11){
        if (day > 30)
            return false;
    }

    if (month == 2){
        bool leap = ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0);
        if (leap && day > 29)
            return false;
        if (!leap && day > 28)
            return false;
    }
    return true;
}

double BitcoinExchange::getExchangeRate(std::string &date) const {
    std::map<std::string, double>::const_iterator it = db.lower_bound(date);

    if (it != db.end() && it->first == date)
        return it->second;
    if (it == db.begin())
        return -1.0;
    --it;
    return it->second;
}

BitcoinExchange::BitcoinExchange(){

}

BitcoinExchange::~BitcoinExchange(){

}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &obj){
    *this = obj;
}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &obj){
    if (this != &obj)
        db = obj.db;
    return *this;
}