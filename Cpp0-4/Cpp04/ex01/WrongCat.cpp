#include "WrongCat.hpp"

WrongCat::WrongCat() : WrongAnimal(){
	std::cout << "WrongCat Default Constructor Called !\n";
	this->type = "WrongCat";
}

WrongCat::WrongCat(const WrongCat& obj){
	std::cout << "WrongCat Copy Constructor Called !\n";
	*this = obj;
}

WrongCat& WrongCat::operator=(const WrongCat& obj){
	this->type = obj.type;
	return (*this);
}

WrongCat::~WrongCat(){
	std::cout << "WrongCat Destructor Called !\n";
}

void WrongCat::makeSound() const{
	std::cout << "WrongCat making sound... [Meow Meow ajmi] !\n";
}