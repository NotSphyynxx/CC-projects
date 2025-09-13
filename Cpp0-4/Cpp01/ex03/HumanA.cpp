#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon& weapon): weapon(weapon){
	set_name(name);
}

void	HumanA::attack(){
	std::cout << get_name() <<
	" attacks with his " <<
	weapon.get_type() << std::endl;
}

std::string	HumanA::get_name(){
	return (name);
}

void	HumanA::set_name(std::string name){
	this->name = name;
}

HumanA::~HumanA(){
	set_name("");
}