#include "Zombie.hpp"


int main(){
	Zombie* horde = zombieHorde(10, "Horde member");
	if (!horde)
	{
		std::cout << "bad_alloc\n";
		return (1);
	}
	for (int i = 0; i < 10; i++){
		horde[i].announcee();
	}
	delete[] horde;
	return (0);
}