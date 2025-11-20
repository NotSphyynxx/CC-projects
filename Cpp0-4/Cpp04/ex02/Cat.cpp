#include "Cat.hpp"

Cat::Cat() : Animal(){
	std::cout << "Cat Default Constructor Called !\n";
	this->type = "Cat";
	cerveaux = new Brain();
}

Cat::Cat(const Cat& obj){
	std::cout << "Cat Copy Constructor Called !\n";
	this->type = obj.type;
	this->cerveaux = new Brain(*obj.cerveaux);
}

Cat& Cat::operator=(const Cat& obj){
	if (this != &obj){
		this->type = obj.type;
		delete cerveaux;
		this->cerveaux = new Brain(*obj.cerveaux);
	}
	return (*this);
}

Cat::~Cat(){
	std::cout << "Cat Destructor Called !\n";
	delete cerveaux;
}

void Cat::makeSound() const{
	std::cout << "Cat making sound... [Meow Meow ajmi] !\n";
}