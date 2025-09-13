#include "Weapon.hpp"

Weapon::Weapon(std::string type){
	setType(type);
}

std::string	Weapon::get_type(void){
	return (type);
}

void Weapon::setType(std::string type){
	this->type = type;
}

Weapon::~Weapon(){
	setType("");
}