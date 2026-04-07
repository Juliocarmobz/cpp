#include "ClassZombie.hpp"
#include <iostream>

void Zombie::randomChump( std::string name )
{
    Zombie random(name);

    random.announce();
}