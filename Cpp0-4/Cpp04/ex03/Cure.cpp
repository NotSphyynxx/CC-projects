#include "Cure.hpp"

Cure::Cure(): AMateria("cure"){
    std::cout << "Cure Constructor Called !\n";
}

Cure::Cure(const Cure& obj) : AMateria(obj){
    std::cout << "Cure Copy Constructor Called !\n";
    if (this != &obj)
        *this = obj;
}

Cure& Cure::operator=(const Cure& obj){
    if (this != &obj)
        this->type = obj.type;
    return (*this);
}

Cure::~Cure(){
    std::cout << "Cure Destructor Called !\n";
}

AMateria* Cure::clone() const{
    return (new Cure(*this));
}

void    Cure::use(ICharacter& target){
    std::cout << "* heals " << target.getName() << "'s wounds *\n";
}