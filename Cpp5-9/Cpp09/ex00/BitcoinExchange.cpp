#include "BitcoinExchange.hpp"
#include <fstream>
#include <cstdlib>

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
            std::cout << "Parsing Error\n";
            return ;            
        }
        double bitcoin;
        if (!isValidValue(bitc, bitcoin)){
            std::cout << "Parsing Error\n";
            return ; 
        }

    }
}

bool BitcoinExchange::isValidValue(std::string &bitc, double &finnal_value) const {
    char *endPtr;

    finnal_value = std::strtod(bitc.c_str(), &endPtr);
    if (bitc.empty() || endPtr != '\0')
        return false;
    if (finnal_value < 0)
        return false;
    if (finnal_value > 1000)
        return false;
    return true;
}

