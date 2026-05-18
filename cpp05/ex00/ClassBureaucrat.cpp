#include "ClassBureaucrat.hpp"
#include <iostream>

Bureaucrat::Bureaucrat () : _name("Default"), _grade(42)
{
    std::cout << "Default constructor called" << std::endl;
    return ;
}

// need to implement validations here? if grade is too high or too low throw a exception here?
Bureaucrat::Bureaucrat (const std::string name, int grade) : _name(name), _grade(grade)
{
    // validations?
    // output operator overload needs to be used here?
    std::cout << this->_name << " created!" << std::endl;
    return ;
}

Bureaucrat & Bureaucrat::operator=(const Bureaucrat & rhs)
{
    std::cout << "Copy assignment operator called" << std::endl;

    if (this == &rhs)
        return (*this);
    this->_name = rhs._name;
    this->_grade = rhs._grade;
    return (*this);
}

Bureaucrat::Bureaucrat (Bureaucrat const & src)
{
    std::cout << "Copy constructor called" << std::endl;
    *this = src;
    return ;
}

Bureaucrat::~Bureaucrat()
{
    std::cout << "Default destructor called" << std::endl;
    return ;
}

// TODO member functions:   []getName()    []getGrade[]      []incrementGrade()   []decrementGrade()



// output operator overload to print in the following format
std::ostream &  operator<<(std::ostream & o, Bureaucrat const & rhs)
{

    // o << rhs. <name>, bureaucrat grade <grade>.
    return (o);
}