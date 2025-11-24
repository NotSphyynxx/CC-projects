#include "Character.hpp"

Character::Character(){
    std::cout << "Character Default Constructor Called !\n";
    name = "Default";
    for (int i = 0;i < 4;i++){
        inv[i] = NULL;
        depot[i] = NULL;
    }
}

Character::Character(std::string const &name){
    std::cout << "Character " << name << " Constructor Called !\n";
    this->name = name;
    for (int i = 0;i < 4;i++){
        inv[i] = NULL;
        depot[i] = NULL;
    }
}

Character::Character(Character const &obj){
    std::cout << "Character Copy Constructor Called !\n";
    if (this != &obj)
        *this = obj;
}

Character& Character::operator=(Character const &obj){
    this->name = obj.name;
    for (int i = 0;i < 4;i++){
        if (inv[i])
            delete inv[i];
        if (obj.inv[i])
            inv[i] = obj.inv[i]->clone();
        else
            inv[i] = NULL;
    }
    for (int i = 0;i < 4;i++){
        if (this->depot[i])
            delete depot[i];
        if (obj.depot[i])
            this->depot[i] = obj.depot[i]->clone();
        else
            depot[i] = NULL;
    }
    return (*this);
}

Character::~Character(){
    std::cout << "Character " << name << " Destructor Called !\n";
    for (int i = 0;i < 4;i++){
        if (inv[i])
            delete inv[i];
        inv[i] = NULL;
        if (depot[i])
            delete depot[i];
        depot[i] = NULL;
    }
}

std::string const& Character::getName() const {
    return (name);
}

void Character::equip(AMateria* m){
    for (int i = 0;i < 4;i++){
        for (int j = 0;j < 4;j++){
            if (inv[j] == m){
                std::cout << "Error u cant equip the same Materia !\n";
                return ;
            }   
        }
        if (!inv[i]){
            inv[i] = m->clone();
            return ;
        }
    }
}

void Character::unequip(int idx){
    if (!(idx >= 0 && idx <= 3) && inv[idx]){
        std::cout << "Invalid Idx !\n"; 
        return ;
    }
    for (int i = 0;i < 4;i++){
        if (!depot[i])
            depot[i] = inv[idx];
        inv[idx] = NULL;
        return ;
    }
    delete depot[0];
    depot[0] = NULL;
    for (int i = 1;i < 4;i++){
        depot[i - 1] = depot[i];
    }
    depot[3] = inv[idx];
    inv[idx] =NULL;
}

void Character::use(int idx, ICharacter& target){
    if (idx >= 0 && idx <= 3 && this->inv[idx])
        this->inv[idx]->use(target);
}