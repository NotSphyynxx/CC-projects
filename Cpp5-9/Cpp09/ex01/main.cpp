#include "RPN.hpp"

int main(int ac, char **av){
    if (ac == 2){
        RPN rpn;
        rpn.calculate(av[1]);
    }
    else
        return 1;
    return 0;
}