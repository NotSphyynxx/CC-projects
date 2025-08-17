#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <iostream>

class Zombie{
	private:
		std::string z_name = "sphynx";
	public:
		Zombie();
		~Zombie();
		void	 	announcee(void);
		std::string	get_name(void);
};

#endif