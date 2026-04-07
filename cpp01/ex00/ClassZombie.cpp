#include "ClassZombie.hpp"

Zombie::Zombie(void)
{
    this->name = "default";
    return ;
}

Zombie::~Zombie(void)
{
    std::cout << "Destroying Zombie: " << this->name << std::endl;
    return ;
}

void    Zombie::announce(void)
{
    std::cout << this->name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

// Zombie* newZombie( std::string name )
// {
//     std::string     Zombie::*p = NULL;
//     Zombie          newzombie;

//     newzombie.*name = name;
//     return (&newzombie);
// }