#include "ClassAnimal.hpp"
#include <iostream>

Animal::Animal () : __type("Default Animal")
{
    std::cout << "Default Animal constructor called" << std::endl;
    return ;
}

Animal::Animal (std::string type) : __type(type)
{
    std::cout << this->__type << " Animal created!" << std::endl;
    return ;
}

Animal::Animal (Animal const & src)
{
    std::cout << "Copy constructor Animal called!" << std::endl;
    *this = src;
    return ;
}

Animal & Animal::operator=(const Animal & rhs)
{
    std::cout << "Copy assignment operator Animal called!" << std::endl;
    if (this != &rhs)
        this->__type = rhs.__type;
    return (*this);
}

Animal::~Animal ()
{
    std::cout << "Default Animal destructor called!" << std::endl;
    return ;
}

std::string     const & Animal::getType() const
{
    return (this->__type);
}

void    Animal::makeSound() const
{
    std::cout << "Default Animal sound" << std::endl;
    return ;
}