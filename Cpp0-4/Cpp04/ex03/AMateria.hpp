#ifndef AMATERIA_HPP
#define AMATERIA_HPP
#include <iostream>
#include "ICharacter.hpp"
class ICharacter;

class AMateria
{
    protected:
    std::string type;
    public:
    AMateria();
    AMateria(const AMateria& obj);
    AMateria& operator=(const AMateria& obj);
    virtual ~AMateria();
    AMateria(std::string const & type);
    virtual AMateria* clone() const = 0;
    virtual void use(ICharacter& target);
    std::string const & getType() const; //Returns the materia type
};


#endif