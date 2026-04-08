#include "ClassWeapon.hpp"
#include "ClassHumanB.hpp"
#include <iostream>

HumanB::HumanB(std::string name) : _name(name)
{
    return ;
}

HumanB::~HumanB()
{
    return ;
}

void    HumanB::attack(void)
{
    std::cout << this->_name << " attacks with their " << this->_weapon->getType() << std::endl;
    return ;
}

void    HumanB::setWeapon(Weapon weapon)
{
    this->_weapon = &weapon;
    return ;
}