#include <iostream>
#include "ClassSample.hpp"

//Canonical default constructor
Sample::Sample (void) : _foo(0)
{
    std::cout << "Default constructor called" << std::endl;
    return ;
}
//Parametric constructor
Sample::Sample (int const n) : _foo(n)
{
    std::cout << "Parametric constructor called" << std::endl;
    return ;
}

//Canonical copy constructor
Sample::Sample (Sample const & src)
{
    std::cout << "Copy constructor called" << std::endl;
    *this = src;
    return ;
}

//Canonical destructor
Sample::~Sample (void)
{
    std::cout << "Destructor called" << std::endl;
    return ;
}

//Getter
int     Sample::getFoo (void) const
{
    return (this->_foo);
}

//Canonical copy assignment operator overload
Sample & Sample::operator=(Sample const & rhs)
{
    std::cout << "Assignment operator called" << std::endl;

    if (this != &rhs)
        this->_foo = rhs.getFoo();
    return (*this);
}

//Ostream operator overload
std::ostream &      operator<<(std::ostream & o, Sample const & i)
{
    o << "The value of _foo is: " << i.getFoo();
    return (o);
}