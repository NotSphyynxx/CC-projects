#include <iostream>
#include <vector>
#include <algorithm>
#include <exception>

class CapIsFull : std::exception {
    const char* what() const throw(); 
};

class NotEnoughNum : std::exception {
    const char* what() const throw();
};

class Span {
    private:
    unsigned int N;
    std::vector<int> depot;
    public:
    Span();
    ~Span();
    Span(const Span &obj);
    Span(unsigned int num);
    Span &operator=(const Span &obj);

    void addNumber(int num);
    int longestSpan();
    int shortestSpan();
    void addMultiNumbers(std::vector<int>::iterator begin, std::vector<int>::iterator end);
};