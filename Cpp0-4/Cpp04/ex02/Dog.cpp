#include "Dog.hpp"

Dog::Dog() : Animal(){
	type = "Dog";
	std::cout << "Dog Constructor Called !\n";
	cerveaux = new Brain();
}

Dog::Dog(const Dog& obj){
	std::cout << "Dog Copy Constructor Called !\n";
	this->type = obj.type;
	this->cerveaux = new Brain(*obj.cerveaux);
}

Dog& Dog::operator=(const Dog& obj){
	if (this != &obj){
		this->type = obj.type;
		delete cerveaux;
		this->cerveaux = new Brain(*obj.cerveaux);
	}
	return (*this);
}

Dog::~Dog(){
	std::cout << "Dog Destructor Called !\n";
	delete cerveaux;
}

void Dog::makeSound() const{
	std::cout << "Dog making sound... [WOOF WOOF al3awd] !\n";
}