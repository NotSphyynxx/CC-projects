#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <iostream>

class Zombie{
	private:
		std::string z_name;
	public:
		Zombie();
		~Zombie();
		void	 	announcee(void);
		std::string	get_name(void);
		void	set_z_name(std::string name);
	};
	Zombie* zombieHorde( int N, std::string name );
#endif