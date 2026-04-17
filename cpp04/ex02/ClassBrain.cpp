#include "ClassBrain.hpp"

Brain::Brain ()
{
    std::cout << "Default Brain constructor called" << std::endl;

    return ;
}

Brain::Brain (Brain const & src)
{
    std::cout << "Copy constructor Brain called!" << std::endl;

    *this = src;
    return ;
}

Brain & Brain::operator=(const Brain & rhs)
{
    std::cout << "Copy assignment operator Brain called!" << std::endl;

    if (this != &rhs)
    {
        for (int i = 0; i < 100; i++)
            this->ideas[i] = rhs.ideas[i];
    }
    return (*this);
}

Brain::~Brain ()
{
    std::cout << "Default Brain destructor called" << std::endl;

    return ;
}

