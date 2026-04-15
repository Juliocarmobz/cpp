/*
    contructors, destructors and attack of scavtrap will print different messages
    when scabtrap is istanciated will construct first claptrap, therefore scavtrap, the destruction is the opposite

    scavtrap will use the attributes of claptrap, name, hitpoints, energy points and attack damage
    method void guardGate() 
*/

#ifndef CLASSSCAVTRAP_HPP
# define CLASSSCAVTRAP_HPP

# include "ClassClapTrap.hpp"
# include <iostream>

class ScavTrap: public ClapTrap
{
    private:


    public:
        ScavTrap ();
        ScavTrap (const std::string name);
        ScavTrap (ScavTrap const & src);
        ~ScavTrap ();
        ScavTrap & operator=(const ScavTrap & rhs);

        void attack(const std::string& target);
        void takeDamage(unsigned int amount);
        void beRepaired(unsigned int amount);
        void guardGate();

};

# endif

ScavTrap a;

