#include "ScalarConverter.hpp"

int main(int ac, char **av) {
    if (ac != 2){
        std::cout << "cmd: ./convert \"literal\"\n";
        return 1;
    }
    else
        ScalarConverter::convert(av[1]);
    return 0;
}