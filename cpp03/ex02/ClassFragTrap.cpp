#include "ClassFragTrap.hpp"
#include "ClassClapTrap.hpp"
#include <iostream>

FragTrap::FragTrap (void) : ClapTrap()
{
    std::cout << this->_name <<" FragTrapper created!" << std::endl;
    this->_hit_points = 100; 
    this->_energy_points = 100;
    this->_attack_damage = 30;
    return ;
}

FragTrap::FragTrap (std::string name) : ClapTrap(name)
{
    std::cout << this->_name <<" FragTrapper created!" << std::endl;
    this->_hit_points = 100; 
    this->_energy_points = 100;
    this->_attack_damage = 30;
    return ;
}

FragTrap & FragTrap::operator=(const FragTrap & rhs)
{
    std::cout << "Copy assignment of FragTrapper operator called" << std::endl;

    if (this == &rhs)
        return (*this);

    this->_name = rhs._name;
    this->_attack_damage = rhs._attack_damage;
    this->_energy_points = rhs._energy_points;
    this->_hit_points = rhs._hit_points;    
    return (*this);
}

FragTrap::FragTrap (FragTrap const & src)
{
    std::cout << "Copy constructor of FragTrap called" << std::endl;
    *this = src;
    return ;
}

FragTrap::~FragTrap()
{
    std::cout << "Default FragTrap destructor called" << std::endl;
    return ;
}

void FragTrap::attack(const std::string& target)
{
    if (this->_energy_points < 1)
    {
        std::cout << "FragTrap " << this->_name << " doesn't have enough Energy Points" << std::endl;
        return ;
    }
    else if (this->_hit_points < 1)
    {
        std::cout << "FragTrap " << this->_name << " is already dead and can not attack!" << std::endl;
        return ;
    }

    this->_energy_points--;
    std::cout << "FragTrap " << this->_name << " attacks " << target << ", causing " << this->_attack_damage << " points of damage!" << std::endl; 
    return ;
}

void FragTrap::takeDamage(unsigned int amount)
{
    if (this->_hit_points < 1)
    {
        std::cout << "FragTrap " << this->_name << " is already dead." << std::endl;
        return ;
    }
    else if (this->_hit_points < amount)
    {
        std::cout << "FragTrap " << this->_name << " received " << amount << " of damage and died." << std::endl;
        this->_hit_points = 0;
        return ;
    }
    this->_hit_points -= amount;
    std::cout << "FragTrap " << this->_name << " took " << amount << " of damage. " << this->_hit_points << " Hit points left!" << std::endl; 
    return ;
}

void FragTrap::beRepaired(unsigned int amount)
{
    if (this->_energy_points < 1)
    {
        std::cout << "FragTrap " << this->_name << " doesn't have enough Energy Points to be repaired!" << std::endl;
        return ;
    }

    this->_energy_points--;
    this->_hit_points += amount;
    std::cout << "FragTrap " << this->_name << " repaired himself in " << amount << " of health. " << this->_hit_points << " Hit points left!" << std::endl;
    return ;
}

void FragTrap::highFivesGuys(void)
{
    if (this->_hit_points < 1)
    {
        std::cout << "FragTrap " << this->_name << " is already dead and cannot positive high-fives request on the standard output." << std::endl;
        return ;
    }
    std::cout << "FragTrap positive high-fives request on the standard output." << std::endl;
    return ;
}