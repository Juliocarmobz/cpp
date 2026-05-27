#include "ClassBureaucrat.hpp"
#include <iostream>

Bureaucrat::Bureaucrat () : _name("Default"), _grade(42)
{
    std::cout << "Default constructor called" << std::endl;
    return ;
}

void    Bureaucrat::gradeValidation (int grade_verfication)
{
    if (grade_verfication < 1)
        throw Bureaucrat::GradeTooHighException();
    else if (grade_verfication > 150)
        throw Bureaucrat::GradeTooLowException();
    return ;
}

Bureaucrat::Bureaucrat (const std::string& name, int grade) : _name(name), _grade(grade)
{
    std::cout << this->_name << " created!" << std::endl;
    gradeValidation(this->_grade);
    return ;
}

Bureaucrat & Bureaucrat::operator=(const Bureaucrat & rhs)
{
    std::cout << "Copy assignment operator called" << std::endl;

    if (this == &rhs)
        return (*this);
    // this->_name = rhs._name; cannot copy _name because is const
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
    std::cout << "Default " << getName() << " destructor called" << std::endl;
    return ;
}

std::string     Bureaucrat::getName (void) const
{
    // std::cout << "getName member function called" << std::endl;
    return (this->_name);
}

int     Bureaucrat::getGrade (void) const
{
    // std::cout << "getName member function called" << std::endl;
    return (this->_grade);
}

void    Bureaucrat::incrementGrade (void)
{
    gradeValidation(this->_grade - 1);
    this->_grade--;
    return ;
}

void    Bureaucrat::decrementGrade (void)
{
    gradeValidation(this->_grade + 1);
    this->_grade++;
    return ;
}

std::ostream &  operator<<(std::ostream & o, Bureaucrat const & rhs)
{
    o << rhs.getName() << ", bureaucrat grade " << rhs.getGrade() << ".";
    return (o);
}