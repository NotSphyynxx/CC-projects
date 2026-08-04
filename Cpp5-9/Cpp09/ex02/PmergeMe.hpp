#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <vector>
#include <deque>
#include <string>
#include <cstdlib>
#include <sys/time.h>


class PmergeMe {
    private:
    std::vector<int> vec;
    std::deque<int> deq;
    

    void fordJohnsonVector(std::vector<int>& arr);
    // void fordJohnsonDeque(std::deque<int>& arr);

    std::vector<int> generateJacobsthal(size_t size);

    public:
    // PmergeMe();
    // ~PmergeMe();
    // PmergeMe(const PmergeMe &obj);
    // PmergeMe &operator=(const PmergeMe &obj);

    void process(int ac, char **av);
    bool parseArguments(int ac, char **av);
};

#endif