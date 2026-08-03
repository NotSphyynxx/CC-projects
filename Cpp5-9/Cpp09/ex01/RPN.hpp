#ifndef RPN_HPP
#define RPN_HPP

#include <iostream>
#include <algorithm>
#include <stdlib.h>
#include <stack>

class RPN {
    private:
    std::stack<int> stack;
    public:

    RPN();
    ~RPN();
    RPN(const RPN &obj);
    RPN &operator=(const RPN &obj);

    bool isOperator(char op);
    bool executeOperation(char op);

    void calculate(const std::string &line);
};

#endif