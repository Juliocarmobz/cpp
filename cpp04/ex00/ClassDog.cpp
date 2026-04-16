#include "ClassAnimal.hpp"
#include "ClassDog.hpp"
#include <iostream>

Dog::Dog () : Animal("Dog")
{
    std::cout << "Default " << this->__type << " constructor called" << std::endl;

    return ;
}

Dog::Dog (Dog const & src) : Animal(src)
{
    std::cout << "Copy constructor Dog called!" << std::endl;
    return ;
}

Dog & Dog::operator=(const Dog & rhs)
{
    std::cout << "Copy assignment operator Dog called!" << std::endl;

    if (this != &rhs)
        this->__type = rhs.__type;
    return (*this);
}

Dog::~Dog ()
{
    std::cout << "Default Dog destructor called!" << std::endl;
    return ;
}

void    Dog::makeSound() const
{
    std::cout << "Woof-woof    bow-wow    arf-arf   ruff-ruff 🐶" << std::endl;
    return ;
}