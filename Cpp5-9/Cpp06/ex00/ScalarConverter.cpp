#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter() {}

ScalarConverter::ScalarConverter(const ScalarConverter& obj){
	(void)obj;
}

ScalarConverter& ScalarConverter::operator=(const ScalarConverter& obj){
	(void)obj;
	return (*this);
}

ScalarConverter::~ScalarConverter(){}

static bool is_char(const std::string &str){
	if (str.length() == 1 && !std::isdigit(str[0]))
		return true;
	return false;
}

static bool is_int(const std::string &str){
	if (str == "+" || str == "-")
		return false;
	char *ptr = NULL;
	std::strtol(str.c_str(), &ptr, 10);
	return (*ptr == '\0');
}

static bool is_float(const std::string &str){
	if (str == "-inff" || str == "+inff" || str == "nanf")
		return true;
	char *ptr = NULL;
	std::strtof(str.c_str(), &ptr);
	return (*ptr == 'f' && *(ptr + 1) == '\0');
}

static bool is_double(const std::string &str){
	if (str == "-inf" || str == "+inf" || str == "nan")
		return true;
	char *ptr = NULL;
	std::strtod(str.c_str(), &ptr);
	return (*ptr == '\0');
}

static void print_char(double num){\
	std::cout << "char: ";
	if (std::isnan(num) || num > 127 || num < 0)
		std::cout << "impossible\n";
	else if (!std::isprint(static_cast<int>(num)))
		std::cout << "Non displayable\n";
	else {
		char c = static_cast<char> (num);
		std::cout << "\'" << c << "\'\n";
	}
}

static void print_int(double num){
	std::cout << "int: ";
	if (std::isnan(num) || num > INT_MAX || num < INT_MIN)
		std::cout << "impossible\n";
	else {
		int var = static_cast<int> (num);
		std::cout << var << "\n";
	}
}

static void print_float(double num){
	std::cout << "float: ";
	float f = static_cast<float>(num);
	if (std::isnan(f) || std::isinf(f))
		std::cout << f << "f\n";
	else if (f == static_cast<int>(num))
		std::cout << std::fixed << std::setprecision(1) << f << "f\n";
	else
		std::cout << std::fixed << std::setprecision(6) << f << "f\n";
	
}

static void print_double(double num){
	std::cout << "double: ";
	if (std::isnan(num) || std::isinf(num))
		std::cout << num << "\n";
	else if (num == static_cast<long long>(num))
		std::cout << std::fixed << std::setprecision(1) << num << "\n";
	else
		std::cout << std::fixed << std::setprecision(1) << num << "\n";
}

void ScalarConverter::convert(const std::string& literal){
	double num = 0.0;
	if (is_char(literal))
		num = static_cast<double> (literal[0]);
	else if (is_int(literal))
		num = static_cast<double> (std::strtol(literal.c_str(), NULL, 10));
	else if (is_float(literal))
		num = static_cast<double> (std::strtof(literal.c_str(), NULL));
	else if (is_double(literal))
		num = static_cast<double> (std::strtod(literal.c_str(), NULL));
	else
		std::cout << "Arg Invalid !!\n";
	print_char(num);
	print_int(num);
	print_float(num);
	print_double(num);


}