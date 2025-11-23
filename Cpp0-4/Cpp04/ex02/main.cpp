#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include "Brain.hpp"

int main()
{
	// const Animal* o = new Animal(); Will produce error
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	std::cout << "=======================================\n";
	// o->makeSound();
	std::cout << "=======================================\n";
	j->makeSound();
	delete j;//should not create a leak
	delete i;
	return 0;
}
