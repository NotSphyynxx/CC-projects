#ifndef CONVERSION_HPP
#define CONVERSION_HPP
#include <iostream>
#include <cmath>
#include <cstdlib>
#include <climits>
#include <iomanip>


class ScalarConverter {
	private:
	ScalarConverter();
	ScalarConverter(const ScalarConverter& obj);
	ScalarConverter& operator=(const ScalarConverter& obj);
	~ScalarConverter();
	public:
	static void convert(const std::string& literal);
};


#endif