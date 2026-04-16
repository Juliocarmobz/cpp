#include "ClassAnimal.hpp"
#include "ClassCat.hpp"
#include <iostream>

Cat::Cat () : Animal("Cat")
{
    std::cout << "Default " << this->__type << " constructor called" << std::endl;

    return ;
}

Cat::Cat (Cat const & src) : Animal(src)
{
    std::cout << "Copy constructor Cat called!" << std::endl;
    return ;
}

Cat & Cat::operator=(const Cat & rhs)
{
    std::cout << "Copy assignment operator Cat called!" << std::endl;

    if (this != &rhs)
        this->__type = rhs.__type;
    return (*this);
}

Cat::~Cat ()
{
    std::cout << "Default Cat destructor called!" << std::endl;
    return ;
}

void    Cat::makeSound() const
{
    std::cout << "Meoww meow   mreeaOOOW mreeaOOOW   Fssss Fssss 🐱" << std::endl;
    return ;
}