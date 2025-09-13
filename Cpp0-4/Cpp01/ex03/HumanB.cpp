#include "HumanB.hpp"

HumanB::HumanB(std::string name){
	set_name(name);
	weapon = NULL;
}

void	HumanB::setWeapon(Weapon& weapon){
	this->weapon = &weapon;
}

void	HumanB::attack(){
	if (!weapon){
		std::cout << get_name()
		<<" don't have a weapon to attack!"
		<< std::endl;
		return ;
	}
	std::cout << get_name() <<
	" attacks with his " <<
	weapon->get_type() << std::endl;
}

std::string	HumanB::get_name(){
	return (name);
}

void	HumanB::set_name(std::string name){
	this->name = name;
}

HumanB::~HumanB(){
	set_name("");
}