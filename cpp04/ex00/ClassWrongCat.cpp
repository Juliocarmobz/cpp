#include "ClassWrongAnimal.hpp"
#include "ClassWrongCat.hpp"
#include <iostream>

WrongCat::WrongCat () : WrongAnimal("WrongCat")
{
    std::cout << "Default " << this->__type << " constructor called" << std::endl;

    return ;
}

WrongCat::WrongCat (WrongCat const & src) : WrongAnimal(src)
{
    std::cout << "Copy constructor WrongCat called!" << std::endl;
    return ;
}

WrongCat & WrongCat::operator=(const WrongCat & rhs)
{
    std::cout << "Copy assignment operator WrongCat called!" << std::endl;

    if (this != &rhs)
        this->__type = rhs.__type;
    return (*this);
}

WrongCat::~WrongCat ()
{
    std::cout << "Default WrongCat destructor called!" << std::endl;
    return ;
}

void    WrongCat::makeSound() const
{
    std::cout << "WrongCat says: Meoww meow   mreeaOOOW mreeaOOOW   Fssss Fssss 🐱" << std::endl;
    return ;
}