#include "MateriaSource.hpp"

MateriaSource::MateriaSource(){
    std::cout << "MateriaSource Default Construtor Called !\n";
    for (int i = 0;i < 4;i++){
        learned[i] = NULL;
    }
}

MateriaSource::MateriaSource(MateriaSource const &obj){
    std::cout << "MateriaSource Copy Constructor Called !\n";
    if (this != &obj){
        for (int i = 0;i < 4;i++){
            if (obj.learned[i])
                learned[i] = obj.learned[i];
            else
                learned[i] = NULL;
        }
    }
}

MateriaSource& MateriaSource::operator=(MateriaSource const &obj){
    if (this != &obj){
        for (int i = 0;i < 4;i++){
            if (learned[i])
                delete learned [i];
            if (obj.learned[i])
                learned[i] = obj.learned[i];
            else
                learned[i] = NULL;
        }
    }
    return (*this);
}

MateriaSource::~MateriaSource(){
    std::cout << "MateriaSource Destructor Called !\n";
    for (int i = 0;i < 4;i++){
        delete learned[i];
    }
}

void MateriaSource::learnMateria(AMateria* m){
    if (!m)
        return ;
    for (int i = 0;i < 4;i++){
        if (!learned[i]){
            learned[i] = m;
            return ;
        }
    }
}

AMateria* MateriaSource::createMateria(std::string const & type){
    for (int i = 0;i < 4;i++){
        if (learned[i] && learned[i]->getType() == type)
            return (learned[i]->clone());
    }
    return NULL;
}