#include "ClassAnimal.hpp"
#include "ClassDog.hpp"
#include <iostream>
# include "ClassBrain.hpp"

Dog::Dog () : Animal("Dog")
{
    std::cout << "Default " << this->__type << " constructor called" << std::endl;
    _brain = new Brain();

    return ;
}

Dog::Dog (Dog const & src) : Animal(src)
{
    std::cout << "Copy constructor Dog called!" << std::endl;
    _brain = new Brain(*src._brain);
    return ;
}

Dog & Dog::operator=(const Dog & rhs)
{
    std::cout << "Copy assignment operator Dog called!" << std::endl;

    if (this != &rhs)
    {
        this->__type = rhs.__type;
        if (this->_brain)
            delete this->_brain;
        this->_brain = new Brain(*rhs._brain);
    }
    return (*this);
}

Dog::~Dog ()
{
    std::cout << "Default Dog destructor called!" << std::endl;
    delete _brain;
    return ;
}

void    Dog::makeSound() const
{
    std::cout << "Woof-woof    bow-wow    arf-arf   ruff-ruff 🐶" << std::endl;
    return ;
}

Brain* Dog::getBrain() const
{
    return (this->_brain);
}