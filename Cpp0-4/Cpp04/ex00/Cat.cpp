#include "Cat.hpp"

Cat::Cat() : Animal(){
	std::cout << "Cat Default Constructor Called !\n";
	this->type = "Cat";
}

Cat::Cat(const Cat& obj){
	std::cout << "Cat Copy Constructor Called !\n";
	*this = obj;
}

Cat& Cat::operator=(const Cat& obj){
	this->type = obj.type;
	return (*this);
}

Cat::~Cat(){
	std::cout << "Cat Destructor Called !\n";
}

void Cat::makeSound() const{
	std::cout << "Cat making sound... [Meow Meow ajmi] !\n";
}