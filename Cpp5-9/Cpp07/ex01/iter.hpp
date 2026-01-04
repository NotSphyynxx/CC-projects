#ifndef ITER_HPP
#define ITER_HPP
#include <iostream>

template <typename T, typename F> 

void iter(T* arr, const size_t arr_length, F func){
	size_t i = 0;
	while (i < arr_length){
		func(arr[i]);
		i++;
	}
}

#endif