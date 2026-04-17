#include <iostream>

class Character
{
    public:
        virtual void    sayHello(std::string const & target);
};

class Warrior : public Character
{
    public:
        virtual void    sayHello(std::string const & target);
};

class Cat
{
    //
};

void    Character::sayHello(std::string const & target)
{
    std::cout << "Character: Hello " << target << std::endl;
}

void    Warrior::sayHello(std::string const & target)
{
    std::cout << "Warrior: Hello " << target << std::endl;
}

int     main(void)
{
    // this is OK, obviously, Warrior IS a Warrior
    Warrior *   a = new Warrior();

    // this is also OK, Warrior IS a Character
    Character * b = new Warrior();

    // this would NOT be ok because Character is NOT a Warrior
    //Warrior * c = new Character();

    // this would NOT be ok either because Cat is NOT  a Character 
    //Character * d = new Cat();
    
    a->sayHello("students");
    b->sayHello("women");
    //delete a;
    //delete b;
    return (0);
}