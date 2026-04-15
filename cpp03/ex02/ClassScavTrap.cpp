#include "ClassScavTrap.hpp"
#include "ClassClapTrap.hpp"
#include <iostream>

ScavTrap::ScavTrap (void) : ClapTrap()
{
    std::cout << this->_name <<" ScavTrapper created!" << std::endl;
    this->_hit_points = 100; 
    this->_energy_points = 50;
    this->_attack_damage = 20;
    return ;
}

ScavTrap::ScavTrap (std::string name) : ClapTrap(name)
{
    std::cout << this->_name <<" ScavTrapper created!" << std::endl;
    this->_hit_points = 100; 
    this->_energy_points = 50;
    this->_attack_damage = 20;
    return ;
}

ScavTrap & ScavTrap::operator=(const ScavTrap & rhs)
{
    std::cout << "Copy assignment of ScavTrapper operator called" << std::endl;

    if (this == &rhs)
        return (*this);

    this->_name = rhs._name;
    this->_attack_damage = rhs._attack_damage;
    this->_energy_points = rhs._energy_points;
    this->_hit_points = rhs._hit_points;    
    return (*this);
}

ScavTrap::ScavTrap (ScavTrap const & src)
{
    std::cout << "Copy constructor of ScavTrap called" << std::endl;
    *this = src;
    return ;
}

ScavTrap::~ScavTrap()
{
    std::cout << "Default ScavTrap destructor called" << std::endl;
    return ;
}

void ScavTrap::attack(const std::string& target)
{
    if (this->_energy_points < 1)
    {
        std::cout << "ScavTrap " << this->_name << " doesn't have enough Energy Points" << std::endl;
        return ;
    }
    else if (this->_hit_points < 1)
    {
        std::cout << "ScavTrap " << this->_name << " is already dead and can not attack!" << std::endl;
        return ;
    }

    this->_energy_points--;
    std::cout << "ScavTrap " << this->_name << " attacks " << target << ", causing " << this->_attack_damage << " points of damage!" << std::endl; 
    return ;
}

void ScavTrap::takeDamage(unsigned int amount)
{
    if (this->_hit_points == 0)
    {
        std::cout << "ScavTrap " << this->_name << " is already dead." << std::endl;
        return ;
    }
    else if (this->_hit_points < amount)
    {
        std::cout << "ScavTrap " << this->_name << " received " << amount << " of damage and died." << std::endl;
        this->_hit_points = 0;
        return ;
    }
    this->_hit_points -= amount;
    std::cout << "ScavTrap " << this->_name << " took " << amount << " of damage. " << this->_hit_points << " Hit points left!" << std::endl; 
    return ;
}

void ScavTrap::beRepaired(unsigned int amount)
{
    if (this->_energy_points < 1)
    {
        std::cout << "ScavTrap " << this->_name << " doesn't have enough Energy Points to be repaired!" << std::endl;
        return ;
    }

    this->_energy_points--;
    this->_hit_points += amount;
    std::cout << "ScavTrap " << this->_name << " repaired himself in " << amount << " of health. " << this->_hit_points << " Hit points left!" << std::endl;
    return ;
}

void ScavTrap::guardGate(void)
{
    if (this->_hit_points < 1)
    {
        std::cout << "ScavTrap " << this->_name << " is already dead and cannot be in Gate keeper mode." << std::endl;
        return ;
    }
    std::cout << "ScavTrap is now in Gate keeper mode." << std::endl;
    return ;
}