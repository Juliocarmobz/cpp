#include "ClassZombie.hpp"

Zombie::Zombie(std::string name) : _name(name)
{
    std::cout << "Creating Zombie: " << this->_name << std::endl;
    return ;
}

Zombie::~Zombie(void)
{
    std::cout << "Destroying Zombie: " << this->_name << std::endl;
    return ;
}

void    Zombie::announce(void)
{
    std::cout << this->_name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}
