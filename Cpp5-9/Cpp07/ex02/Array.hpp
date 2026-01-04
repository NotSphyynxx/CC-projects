#ifndef ARRAY_HPP
#define ARRAY_HPP
#include <stdexcept>
#include <iostream>

template <typename T>
class Array {
	private:
	T*	arr;
	unsigned int len;
	public:
	Array(){
		arr = NULL;
	};
	Array(const unsigned int n){
		arr = new T[n];
		len = n;
	};
	Array(const Array& obj){
		arr = NULL;
		*this = obj;
	};
	Array& operator=(const Array& obj){
		if (this != &obj){
			if (arr)
				delete[] arr;
			arr = new T[obj.len];
			for (unsigned int i = 0;i < obj.len;i++){
				arr[i] = obj.arr[i];
			}
		}
		this->len = obj.len;
		return (*this);
	};
	T& operator[](const size_t val){
		if (val > len){
			throw std::runtime_error("index out of bounds !!");
		}
		return this->arr[val];
	};
	~Array(){
		if (arr)
			delete[] arr;
	};
	unsigned int	size(){
		return (len);
	};
};

#endif