#ifndef CLASSHUMANA_HPP
# define CLASSHUMANA_HPP

# include "ClassWeapon.hpp"
# include <iostream>

class HumanA
{
    private:
        std::string     _name;
        Weapon&          _weapon;
    public:
        HumanA(std::string name, Weapon& weapon);
        ~HumanA();
        void            attack(void);

};

#endif