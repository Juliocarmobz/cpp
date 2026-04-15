#include "ClassClapTrap.hpp"
#include <iostream>

int     main(void)
{
    ClapTrap robotA("Robot A");

    robotA.attack("Fictitious Robot");
    robotA.takeDamage(5);
    robotA.beRepaired(1);
    robotA.takeDamage(10000);
    robotA.attack("Fictitious Robot");

    return (0);
}