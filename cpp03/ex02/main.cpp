#include "ClassClapTrap.hpp"
#include <iostream>
#include "ClassFragTrap.hpp"

int     main(void)
{
    FragTrap robotA("Robot A");

    robotA.attack("Fictitious Robot");
    robotA.takeDamage(5);
    robotA.beRepaired(1);
    robotA.takeDamage(10000);
    robotA.attack("Fictitious Robot");
    robotA.highFivesGuys();

    return (0);
}