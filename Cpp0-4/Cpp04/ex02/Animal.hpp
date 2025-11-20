#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <iostream>

class Animal {
	protected:
		std::string type;
	public:
	Animal();
	Animal(const Animal& obj);
	Animal& operator=(const Animal& obj);
	virtual ~Animal();
	std::string getType( void ) const;
    void        setType( std::string const &type );
	virtual void makeSound() const = 0;
};


#endif