#ifndef CLASSFRAGTRAP_HPP
# define CLASSFRAGTRAP_HPP

# include "ClassClapTrap.hpp"
# include <iostream>

class FragTrap: public ClapTrap
{
    private:


    public:
        FragTrap ();
        FragTrap (const std::string name);
        FragTrap (FragTrap const & src);
        ~FragTrap ();
        FragTrap & operator=(const FragTrap & rhs);

        void attack(const std::string& target);
        void takeDamage(unsigned int amount);
        void beRepaired(unsigned int amount);
        void highFivesGuys(void);

};

# endif