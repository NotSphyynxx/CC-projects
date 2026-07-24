#include "Span.hpp"

const char* CapIsFull::what() const throw() {
    return "Array capacity is full !!";
}

const char* NotEnoughNum::what() const throw() {
    return "Not enough numbers !!";
}

Span::Span() : N(0) {

}

Span::~Span() {

}

Span::Span(const Span &obj) : N(obj.N), depot(obj.depot) {

}

Span::Span(unsigned int num) : N(num) {

}

Span &Span::operator=(const Span &obj) {
    if (this != &obj){
        N = obj.N;
        depot = obj.depot;
    }
    return *this;
}

void Span::addNumber(int num){
    if (depot.size() + 1 > N)
        throw CapIsFull();
    depot.push_back(num);
    std::sort(depot.begin(), depot.end());
}

int Span::longestSpan() {
    if (depot.size() < 2)
        throw NotEnoughNum();
    return (*(depot.end() - 1) - *depot.begin()); 
}

int Span::shortestSpan() {
    if (depot.size() < 2)
        throw NotEnoughNum();
    std::vector<int>::iterator curr = depot.begin();
    std::vector<int>::iterator next = depot.begin();
    ++next;
    int shortestYet = *next - *curr;
    while (next != depot.end()){
        int tmp = *next - *curr;
        if (tmp < shortestYet)
            shortestYet = tmp;
        ++curr;
        ++next;
    }
    return shortestYet;
}

void Span::addMultiNumbers(std::vector<int>::iterator begin, std::vector<int>::iterator end){
    while (begin != end){
        if (depot.size() + 1 > N)
            throw CapIsFull();
        depot.push_back(*begin);
        ++begin;
    }
    std::sort(depot.begin(), depot.end());
}