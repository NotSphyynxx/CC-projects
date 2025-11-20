#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal(){
	std::cout << "WrongAnimal Default Constructor Called !\n";
}

WrongAnimal::WrongAnimal(const WrongAnimal& obj){
	std::cout << "WrongAnimal Copy Constructor Called\n";
	if (this != &obj)
		*this = obj;
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal& obj){
	this->type = obj.type;
	return (*this);
}

WrongAnimal::~WrongAnimal(){
	std::cout << "WrongAnimal Destructor Called !\n";
}

std::string WrongAnimal::getType( void ) const{
	return (type);
}

void WrongAnimal::setType( std::string const &type ){
	this->type = type;
}

void WrongAnimal::makeSound() const{
	std::cout << "WrongAnimal sound... [Zzzzzz] !\n";
}