#include "BitcoinExchange.hpp"

int main(){
    BitcoinExchange sphynx;
    sphynx.loadDatabase("data.csv");
    std::map<std::string, double>::iterator it;
    for (it = sphynx.db.begin(); it != sphynx.db.end(); ++it) {
        std::cout << "Date: " << it->first << " | Prix: " << it->second << "\n";
    }
}