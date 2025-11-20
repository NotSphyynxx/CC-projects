#include "ClapTrap.hpp"

ClapTrap::ClapTrap() : name("Default"), Hit_points(10), Energy_points(10), Attack_damage(0)  {
    std::cout << "Default constructor called !\n";
}

ClapTrap::ClapTrap(std::string name){
    std::cout << "Parameterized Constructor called for" << name << " !\n";
    this->name = name;
    Hit_points = 10;
    Energy_points = 10;
    Attack_damage = 0;
}

ClapTrap::ClapTrap(const ClapTrap &obj){
    std::cout << "Copy constructor called !\n";
    *this = obj;
}

ClapTrap& ClapTrap::operator=(const ClapTrap& obj){

    std::cout << "Copy assignment operator called !\n";
    this->name = obj.name;
    this->Hit_points = obj.Hit_points;
    this->Energy_points = obj.Energy_points;
    this->Attack_damage = obj.Attack_damage;
    return (*this);
}

ClapTrap::~ClapTrap(){
    std::cout << "Destructor called !\n";
}

void ClapTrap::attack(const std::string& target){
    if (!Hit_points || !Energy_points){
        std::cout << "Not Enough Energy points or " << name << " is dead to attack !\n";
        return ;
    }
    std::cout << "ClapTrap " << name << " attackes " << target 
    << " causing " << Attack_damage << " of damage !\n";
    Energy_points--;
}

void ClapTrap::takeDamage(unsigned int amount){
    std::cout << "ClapTrap " << name << " took " << amount << " of damage !\n";
    Hit_points -= amount;
    if (Hit_points < 0)
        Hit_points = 0;
    if (Hit_points == 0){
        std::cout << "ClapTrap " << name << " is dead !\n";
        return ;
    }
}

void ClapTrap::beRepaired(unsigned int amount){
    if (!Energy_points || !Hit_points){
        std::cout << "Not enough Energy Or " << name << " is dead to be repaired!\n";
        return ;
    }
    std::cout << "ClapTrap " << name << " repaired " << amount << " !\n";
    Energy_points--;
    Hit_points += amount;
}
