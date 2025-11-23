#include "AMateria.hpp"

AMateria::AMateria(){
    std::cout << "AMateria Default Constructor Called !\n";
    type = "Default";
}

AMateria::AMateria(const AMateria& obj){
    std::cout << "AMateria Copy Constructor Called !\n";
    if (this != &obj)
        *this = obj;
}

AMateria& AMateria::operator=(const AMateria& obj){
    this->type = obj.type;
    return (*this);
}

AMateria::~AMateria(){
    std::cout << "AMateria Destructor Called !\n";
}

AMateria::AMateria(std::string const & type){
    std::cout << "AMateria Parametrized Constructor Called For " << type << " !\n";
    this->type = type;
}

std::string const & AMateria::getType() const {
    return (type);
}

void AMateria::use(ICharacter& target){
    std::cout << type << " uses on " << target.getName() << std::endl;
}