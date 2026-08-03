#include "RPN.hpp"

RPN::RPN() {

}
RPN::~RPN(){

}

RPN::RPN(const RPN &obj) {
    *this = obj;
}

RPN &RPN::operator=(const RPN &obj){
    if (this != &obj)
        stack = obj.stack;
    return *this;
}

bool RPN::isOperator(char op){
    if (op == '+' || op == '-' || op == '*' || op == '/')
        return true;
    return false;
}

void RPN::calculate(const std::string &line){
    for (size_t i =0; i < line.length();i++){
        char c = line[i];

        if (c == ' ')
            continue;
        else if (isdigit(c))
            stack.push(c - '0');
        else if (isOperator(c)){
            if (!executeOperation(c))
                return ;
        }
        else {
            std::cout << "Error\n";
            return ;
        }
    }
    if (stack.size() == 1)
        std::cout << stack.top() << std::endl;
    else{
        std::cout << "Too much stack elements\n";
        return;
    }
}

bool RPN::executeOperation(char op){
    if (stack.size() < 2){
        std::cout << "Not enough stack elements\n";
        return false;
    }

    int num2 = stack.top();
    stack.pop();
    int num1 = stack.top();
    stack.pop();

    int res = 0;
    if (op == '+') res = num1 + num2;
    if (op == '-') res = num1 - num2;
    if (op == '*') res = num1 * num2;
    if (op == '/'){
        if (num2 == 0){
            std::cout << "Can't divide by zero !\n";
            return false;          
        }
        res = num1 / num2;
    }
    stack.push(res);
    return true;
}