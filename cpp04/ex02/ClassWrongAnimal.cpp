#include "ClassWrongAnimal.hpp"
#include <iostream>

WrongAnimal::WrongAnimal () : __type("Default WrongAnimal")
{
    std::cout << "Default WrongAnimal constructor called" << std::endl;
    return ;
}

WrongAnimal::WrongAnimal (std::string type) : __type(type)
{
    std::cout << this->__type << " WrongAnimal created!" << std::endl;
    return ;
}

WrongAnimal::WrongAnimal (WrongAnimal const & src)
{
    std::cout << "Copy constructor WrongAnimal called!" << std::endl;
    *this = src;
    return ;
}

WrongAnimal & WrongAnimal::operator=(const WrongAnimal & rhs)
{
    std::cout << "Copy assignment operator WrongAnimal called!" << std::endl;
    if (this != &rhs)
        this->__type = rhs.__type;
    return (*this);
}

WrongAnimal::~WrongAnimal ()
{
    std::cout << "Default WrongAnimal destructor called!" << std::endl;
    return ;
}

std::string     const & WrongAnimal::getType() const
{
    return (this->__type);
}

void    WrongAnimal::makeSound() const
{
    std::cout << "Default WrongAnimal sound" << std::endl;
    return ;
}