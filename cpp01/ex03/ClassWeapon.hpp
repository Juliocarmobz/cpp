#ifndef CLASSWEAPON_HPP
# define CLASSWEAPON_HPP
# include <iostream>

class Weapon
{
    private:
        std::string     _type;
    public:
        Weapon(std::string type);
        ~Weapon();
        std::string     const & getType();
        void            setType(std::string newType);
};

#endif