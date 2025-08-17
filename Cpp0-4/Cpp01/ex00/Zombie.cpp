#include "Zombie.hpp"

Zombie::Zombie(){
	std::cout << this->z_name
	<< " just spawned ^_^\n" << std::endl;
}

Zombie::~Zombie(){
	std::cout << this->z_name
	<< " despawned x_x" << std::endl;
}

std::string Zombie::get_name(){
	return (this->z_name);
}

void	Zombie::announcee(){
	std::cout << get_name()
	<< ": BraiiiiiiinnnzzzZ...\n" << std::endl;
}