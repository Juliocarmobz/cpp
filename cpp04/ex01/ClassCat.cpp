#include "ClassAnimal.hpp"
#include "ClassCat.hpp"
#include <iostream>
# include "ClassBrain.hpp"

Cat::Cat () : Animal("Cat")
{
    std::cout << "Default " << this->__type << " constructor called" << std::endl;
    _brain = new Brain();
    
    return ;
}

Cat::Cat (Cat const & src) : Animal(src)
{
    std::cout << "Copy constructor Cat called!" << std::endl;
    this->_brain = NULL;
    return ;
}

Cat & Cat::operator=(const Cat & rhs)
{
    std::cout << "Copy assignment operator Cat called!" << std::endl;

    if (this != &rhs)
    {
        this->__type = rhs.__type;
        if (this->_brain)
            delete this->_brain;
        this->_brain = new Brain(*rhs._brain);
    }
    return (*this);
}

Cat::~Cat ()
{
    std::cout << "Default Cat destructor called!" << std::endl;
    delete _brain;
    return ;
}

void    Cat::makeSound() const
{
    std::cout << "Meoww meow   mreeaOOOW mreeaOOOW   Fssss Fssss 🐱" << std::endl;
    return ;
}

Brain* Cat::getBrain() const
{
    return (this->_brain);
}