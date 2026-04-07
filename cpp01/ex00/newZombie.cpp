#include "ClassZombie.hpp"
#include <iostream>

Zombie* newZombie( std::string name )
{
    Zombie* newzombie = new Zombie(name);
    return (newzombie);
}
