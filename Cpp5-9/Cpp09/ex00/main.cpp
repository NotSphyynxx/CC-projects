#include "BitcoinExchange.hpp"

int main(int ac, char **av){
    if (ac != 2)
        return 1;
    BitcoinExchange sphynx;
    sphynx.loadDatabase("data.csv");
    sphynx.parseInput(av[1]);
    return 0;
}