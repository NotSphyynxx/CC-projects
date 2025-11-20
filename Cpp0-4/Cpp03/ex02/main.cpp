#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main(){
    ClapTrap x;
    x.attack("zlayji");
    x.takeDamage(100);
    x.beRepaired(111);
    ScavTrap z("zozo");
    z.attack("mojojojo");
    z.guardGate();
    FragTrap y;
    y.highFivesGuys();
;}