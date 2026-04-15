#include "ClassClapTrap.hpp"
#include <iostream>

ClapTrap::ClapTrap () :  _name("Default"), _hit_points(10), _energy_points(10), _attack_damage(0)
{
    std::cout << "Default constructor called" << std::endl;
    return ;
}

ClapTrap::ClapTrap (const std::string name) : _name(name), _hit_points(10), _energy_points(10), _attack_damage(0)
{
    std::cout << this->_name <<" created!" << std::endl;
    return ;
}

ClapTrap & ClapTrap::operator=(const ClapTrap & rhs)
{
    std::cout << "Copy assignment operator called" << std::endl;

    if (this == &rhs)
        return (*this);

    this->_name = rhs._name;
    this->_attack_damage = rhs._attack_damage;
    this->_energy_points = rhs._energy_points;
    this->_hit_points = rhs._hit_points;    
    return (*this);
}

ClapTrap::ClapTrap (ClapTrap const & src)
{
    std::cout << "Copy constructor called" << std::endl;
    *this = src;
    return ;
}

ClapTrap::~ClapTrap()
{
    std::cout << "Default destructor called" << std::endl;
    return ;
}

void ClapTrap::attack(const std::string& target)
{
    if (this->_energy_points < 1)
    {
        std::cout << "ClapTrap " << this->_name << " doesn't have enough Energy Points" << std::endl;
        return ;
    }
    else if (this->_hit_points < 1)
    {
        std::cout << "ClapTrap " << this->_name << " is already dead and can not attack!" << std::endl;
        return ;
    }

    this->_energy_points--;
    std::cout << "ClapTrap " << this->_name << " attacks " << target << ", causing " << this->_attack_damage << " points of damage!" << std::endl; 
    return ;
}

void ClapTrap::takeDamage(unsigned int amount)
{
    if (this->_hit_points == 0)
    {
        std::cout << "ClapTrap " << this->_name << " is already dead." << std::endl;
        return ;
    }
    else if (this->_hit_points < amount)
    {
        std::cout << "ClapTrap " << this->_name << " received " << amount << " of damage and died." << std::endl;
        this->_hit_points = 0;
        return ;
    }
    this->_hit_points -= amount;
    std::cout << "ClapTrap " << this->_name << " took " << amount << " of damage. " << this->_hit_points << " Hit points left!" << std::endl; 
    return ;
}

void ClapTrap::beRepaired(unsigned int amount)
{
    if (this->_energy_points < 1)
    {
        std::cout << "ClapTrap " << this->_name << " doesn't have enough Energy Points to be repaired!" << std::endl;
        return ;
    }

    this->_energy_points--;
    this->_hit_points += amount;
    std::cout << "ClapTrap " << this->_name << " repaired himself in " << amount << " of health. " << this->_hit_points << " Hit points left!" << std::endl;
    return ;
}
