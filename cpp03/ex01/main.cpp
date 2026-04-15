#include "ClassClapTrap.hpp"
#include <iostream>
#include "ClassScavTrap.hpp"

int     main(void)
{
    ScavTrap robotA("Robot A");

    robotA.attack("Fictitious Robot");
    robotA.takeDamage(5);
    robotA.beRepaired(1);
    robotA.takeDamage(10000);
    robotA.attack("Fictitious Robot");
    robotA.guardGate();

    return (0);
}