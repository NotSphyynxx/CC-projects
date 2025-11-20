#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main(){
    ClapTrap x;
    x.attack("zlayji");
    x.takeDamage(5);
    x.beRepaired(5);
    ScavTrap z("zozo");
    z.attack("mojojojo");
    z.guardGate()
;}