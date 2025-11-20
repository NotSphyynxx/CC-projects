#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap("Default"){
       std::cout << "ScavTrap Default constructor called !\n";
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name){
    std::cout << "ScavTrap Parameterized Constructor called for "
    << name << " !\n";

}

ScavTrap::ScavTrap(const ScavTrap& obj) : ClapTrap(obj){
    std::cout << "ScavTrap copy constructor called !\n";
}

ScavTrap& ScavTrap::operator=(const ScavTrap& obj){
    if (this != &obj)
        ClapTrap::operator=(obj);
    return (*this);
}

ScavTrap::~ScavTrap(){
    std::cout << "ScavTrap destructor called !\n";
}

void    ScavTrap::attack(const std::string& target){
    if (!ClapTrap::Hit_points || !ClapTrap::Energy_points){
        std::cout << "Not Enough Energy points or " << name << " is dead to attack !\n";
        return ;
    }
    std::cout << "ScavTrap " << name << " attackes " << target 
    << " causing " << Attack_damage << " of damage !\n";
    Energy_points--;
}

void    ScavTrap::takeDamage(unsigned int amount){
    std::cout << "ScavTrap " << name << " took " << amount << " of damage !\n";
    Hit_points -= amount;
    if (Hit_points < 0)
        Hit_points = 0;
    if (Hit_points == 0){
        std::cout << "ScavTrap " << name << " is dead !\n";
        return ;
    }
}

void    ScavTrap::beRepaired(unsigned int amount){
    if (!ClapTrap::Energy_points || !ClapTrap::Hit_points){
        std::cout << "Not enough Energy Or " << name << " is dead to be repaired!\n";
        return ;
    }
    std::cout << "ScavTrap " << name << " repaired " << amount << " !\n";
    Energy_points--;
    Hit_points += amount;
}

void    ScavTrap::guardGate(){
    std::cout << "ScavTrap " << name << " is now in Gate keeper mode\n";
}
