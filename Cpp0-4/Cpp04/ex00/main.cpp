#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main()
{
	// std::cout << "==================| Subj Test |==================\n";
	// {
	// 	const Animal* meta = new Animal();
	// 	const Animal* j = new Dog();
	// 	const Animal* i = new Cat();
	// 	std::cout << j->getType() << " " << std::endl;
	// 	std::cout << i->getType() << " " << std::endl;
	// 	i->makeSound(); //will output the cat sound!
	// 	j->makeSound();
	// 	meta->makeSound();
	// 	delete meta;
	// 	delete j;
	// 	delete i;
	// }
	// std::cout << "==================| Wrong Test |==================\n";
	// {
	// 	const WrongAnimal* asebban = new WrongAnimal();
	// 	const WrongAnimal* psps = new WrongCat();
	// 	std::cout << psps->getType() << " " << std::endl;
	// 	psps->makeSound(); //will output the cat sound!
	// 	asebban->makeSound();
	// 	delete asebban;
	// 	delete psps;
	// }=
	return 0;
}