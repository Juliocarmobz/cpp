#include "ClassZombie.hpp"

Zombie::Zombie()
{
    std::cout << "Zombie Created" << std::endl;
    return ;
}

Zombie::~Zombie(void)
{
    std::cout << "Destroying Zombie: " << this->_name << std::endl;
    return ;
}

void    Zombie::setName(std::string name)
{
    this->_name = name;
    std::cout << "Creating Zombie: " << this->_name << std::endl;
    return ;
}

void    Zombie::announce(void)
{
    std::cout << this->_name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}
