#include <iostream>

int main(){
	std::string string;

	string = "HI THIS IS BRAIN";
	std::string* stringPTR = &string;
	std::string& stringREF = string;
	std::cout << &string << '\n'<< stringPTR
	<< '\n'<< &stringREF << std::endl;
	std::cout << "----------------\n";
	std::cout << string << '\n'<< *stringPTR
	<< '\n' << stringREF << std::endl;
}
