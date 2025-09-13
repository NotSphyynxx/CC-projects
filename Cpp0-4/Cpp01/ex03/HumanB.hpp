#ifndef HUMANB_HPP
#define HUMANB_HPP

#include <iostream>
#include "Weapon.hpp"
class HumanB{
	private:
		std::string	name;
		Weapon*		weapon;
	public:
	HumanB(std::string name);
	~HumanB();
	std::string	get_name();
	void		set_name(std::string name);
	void		attack();
	void		setWeapon(Weapon& weapon);
};

#endif