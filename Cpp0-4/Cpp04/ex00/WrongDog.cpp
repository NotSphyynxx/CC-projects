#include "WrongDog.hpp"

WrongDog::WrongDog() : WrongAnimal(){
	type = "WrongDog";
	std::cout << "WrongDog Constructor Called !\n";
}

WrongDog::WrongDog(const WrongDog& obj){
	std::cout << "WrongDog Copy Constructor Called !\n";
	*this = obj;
}

WrongDog& WrongDog::operator=(const WrongDog& obj){
	this->type = obj.type;
	return (*this);
}

WrongDog::~WrongDog(){
	std::cout << "WrongDog Destructor Called !\n";
}

void WrongDog::makeSound() const{
	std::cout << "WrongDog making sound... [WOOF WOOF al3awd] !\n";
}