#ifndef CLASSHUMANB_HPP
# define CLASSHUMANB_HPP

# include "ClassWeapon.hpp"
# include <iostream>

class HumanB
{
    private:
        std::string     _name;
        Weapon*          _weapon;
    public:
        HumanB(std::string name);
        ~HumanB();
        void            attack(void);
        void    setWeapon(Weapon weapon);

};

#endif