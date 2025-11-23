#include "Ice.hpp"

Ice::Ice(): AMateria("ice"){
    std::cout << "Ice Constructor Called !\n";
}

Ice::Ice(const Ice& obj): AMateria(obj){
    std::cout << "Ice Copy Constructor Called !\n";
    if (this != &obj)
        *this = obj;
}

Ice& Ice::operator=(const Ice& obj){
    if (this != &obj)
        this->type = obj.type;
    return (*this);
}

Ice::~Ice(){
    std::cout << "Ice Destructor Called !\n";
}

AMateria* Ice::clone() const{
    return (new Ice(*this));
}

void Ice::use(ICharacter& target){
    std::cout << "* shoots an ice bolt at " << target.getName() << " *\n";
}