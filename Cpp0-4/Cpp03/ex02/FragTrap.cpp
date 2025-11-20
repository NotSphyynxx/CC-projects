#include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap("Default"){
    std::cout << "FragTrap Default constructor called !\n";
}

FragTrap::FragTrap(std::string name) : ClapTrap(name) {
    std::cout << "FragTrap Parameterized constructor called for "
    << name << " !\n";
}

FragTrap::FragTrap(const FragTrap& obj) : ClapTrap(obj){
    std::cout << "FragTrap Copy constructor called !\n";
}

FragTrap& FragTrap::operator=(const FragTrap& obj){
    if (this != &obj)
        ClapTrap::operator=(obj);
    return (*this);
}

FragTrap::~FragTrap(){
    std::cout << "FragTrap Deconstructor called !\n";
}

void    FragTrap::attack(const std::string& target){
    if (!ClapTrap::Hit_points || !ClapTrap::Energy_points){
        std::cout << "Not Enough Energy points or " << name << " is dead to attack !\n";
        return ;
    }
    std::cout << "FragTrap " << name << " attackes " << target 
    << " causing " << Attack_damage << " of damage !\n";
    Energy_points--;
}

void    FragTrap::takeDamage(unsigned int amount){
    std::cout << "FragTrap " << name << " took " << amount << " of damage !\n";
    Hit_points -= amount;
    if (Hit_points < 0)
        Hit_points = 0;
    if (Hit_points == 0){
        std::cout << "FragTrap " << name << " is dead !\n";
        return ;
    }
}

void    FragTrap::beRepaired(unsigned int amount){
    if (!ClapTrap::Energy_points || !ClapTrap::Hit_points){
        std::cout << "Not enough Energy Or " << name << " is dead to be repaired!\n";
        return ;
    }
    std::cout << "FragTrap " << name << " repaired " << amount << " !\n";
    Energy_points--;
    Hit_points += amount;
}

void    FragTrap::highFivesGuys(void){
    std::cout << "FragTrap is throwing High fives !!\n";
}
