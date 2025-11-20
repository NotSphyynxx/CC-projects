#include "Dog.hpp"

Dog::Dog() : Animal(){
	type = "Dog";
	std::cout << "Dog Constructor Called !\n";
}

Dog::Dog(const Dog& obj){
	std::cout << "Dog Copy Constructor Called !\n";
	*this = obj;
}

Dog& Dog::operator=(const Dog& obj){
	this->type = obj.type;
	return (*this);
}

Dog::~Dog(){
	std::cout << "Dog Destructor Called !\n";
}

void Dog::makeSound() const{
	std::cout << "Dog making sound... [WOOF WOOF al3awd] !\n";
}