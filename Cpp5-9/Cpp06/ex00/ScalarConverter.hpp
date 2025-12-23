#ifndef CONVERSION_HPP
#define CONVERSION_HPP
#include <iostream>


class ScalarConverter {
	private:
	ScalarConverter();
	ScalarConverter(const ScalarConverter& obj);
	ScalarConverter& operator=(const ScalarConverter& obj);
	~ScalarConverter();
	public:
	static void convert(std::string& literal)
};


#endif