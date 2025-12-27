#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <cstdlib>
#include <time.h>
#include <iostream>

Base * generate(void){
	int ran = std::rand() % 3;

	switch (ran)
	{
		case 0:{
			std::cout << "Generated A\n";
			return (new A());
		}
		case 1:{
			std::cout << "Generated B\n";
			return (new B());
		}
		case 2:{
			std::cout << "Generated C\n";
			return (new C());
		}
		default:{
			std::cout << "Failed to generate :(\n";
			return NULL;
		}
	}

}

void identify(Base* p){
	std::cout << "identifying the object pointed to: ";
	if (dynamic_cast<A *>(p))
		std::cout << "A\n";
	else if (dynamic_cast<B *>(p))
		std::cout << "B\n";
	else if (dynamic_cast<C *>(p))
		std::cout << "C\n";
	else
		std::cout << "unknown !\n";
}

void identify(Base& p){
	std::cout << "identifying the object referenced to: ";
	try{
		(void)dynamic_cast<A&>(p);
		std::cout << "A\n";
	}
	catch(...){}
	try{
		(void)dynamic_cast<B&>(p);
		std::cout << "B\n";
	}
	catch(...){}
	try{
		(void)dynamic_cast<C&>(p);
		std::cout << "C\n";
	}
	catch(...){}
}

int main(){
	std::srand(time(NULL));
	Base *ptr = NULL;
	ptr = generate();
	identify(ptr);
	identify(*ptr);
	if (ptr)
		delete ptr;
	return 0;
}