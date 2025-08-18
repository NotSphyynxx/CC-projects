#include "Zombie.hpp"

Zombie*	newZombie( std::string name ){
	Zombie *new_z = new Zombie;
	new_z->set_z_name(name);
	new_z->announcee();
	return (new_z);
}