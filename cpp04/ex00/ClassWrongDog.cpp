#include "ClassWrongAnimal.hpp"
#include "ClassWrongDog.hpp"
#include <iostream>

WrongDog::WrongDog () : WrongAnimal("WrongDog")
{
    std::cout << "Default " << this->__type << " constructor called" << std::endl;

    return ;
}

WrongDog::WrongDog (WrongDog const & src) : WrongAnimal(src)
{
    std::cout << "Copy constructor WrongDog called!" << std::endl;
    return ;
}

WrongDog & WrongDog::operator=(const WrongDog & rhs)
{
    std::cout << "Copy assignment operator WrongDog called!" << std::endl;

    if (this != &rhs)
        this->__type = rhs.__type;
    return (*this);
}

WrongDog::~WrongDog ()
{
    std::cout << "Default WrongDog destructor called!" << std::endl;
    return ;
}

void    WrongDog::makeSound() const
{
    std::cout << "WrongDog says: Woof-woof    bow-wow    arf-arf   ruff-ruff 🐶" << std::endl;
    return ;
}