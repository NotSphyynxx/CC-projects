#ifndef EASY_FIND_HPP
#define EASY_FIND_HPP

#include <iostream>
#include <algorithm>
#include <vector>

class NotFound : public std::exception {
    const char* what () const throw();
};

template <typename T> 
typename T::iterator EasyFind(T &container, int num)
{
    typename T::iterator it;

    it = std::find(container.begin(), container.end(), num);
    if (it == container.end())
        throw NotFound();
    else
        return it;
}

#endif