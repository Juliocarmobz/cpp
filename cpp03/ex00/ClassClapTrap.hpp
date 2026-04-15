#ifndef CLASSCLAPTRAP_HPP
# define CLASSCLAPTRAP_HPP
# include <iostream>

class ClapTrap
{

    private:
        std::string                  _name;
        unsigned int                 _hit_points; //initialized with 10
        unsigned int                 _energy_points; //initialized with 10
        unsigned int                 _attack_damage; //initialized with 0

    public:
        //TODO canonical orhodox class form 
        ClapTrap ();
        ClapTrap (const std::string name);
        ClapTrap (ClapTrap const & src);
        ~ClapTrap ();
        ClapTrap & operator=(const ClapTrap & rhs);

        void attack(const std::string& target);
        void takeDamage(unsigned int amount);
        void beRepaired(unsigned int amount);


};

#endif