#include <iostream>
#include <fstream>

int main(){
	std::string buffer;
	std::ifstream f("test.txt");
	if (!f.is_open())
		return (1);
	std::ofstream o("out.txt");
	if (!o.is_open())
		return (1);
	while (std::getline(f, buffer)){
		o << buffer;
		if (f.eof()){
			std::cout << "EOF reached\n";
			break ;
		}
		else
			o << std::endl;
	}
	o.close();
	f.close();
}