#include "Bureaucrat.hpp"
#include "AForm.hpp"
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

const char *Bureaucrat::GradeTooHighException::what() const throw()
{
    return ("Exception: The Grade is Too High");

}

const char *Bureaucrat::GradeTooLowException::what() const throw()
{
    return ("Exception: The Grade is Too Low");
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

void Bureaucrat::signForm(AForm & form)
{
    try
    {
        form.beSigned(*this);
        std::cout << this->_name << " signed " << form.getName() << std::endl;
    }
    catch (std::exception & e)
    {
        std::cout << this->_name << " couldn't sign " << form.getName() << " because " << e.what() << std::endl;
    }
}

void Bureaucrat::executeForm(AForm & form)
{
    try
    {
        form.execute(*this);
        std::cout << this->_name << " executed " << form.getName() << std::endl;
    }
    catch (std::exception & e)
    {
        std::cout << this->_name << " couldn't execute " << form.getName() << " because " << e.what() << std::endl;
    }
}

std::ostream &  operator<<(std::ostream & o, Bureaucrat const & rhs)
{
    o << rhs.getName() << ", bureaucrat grade " << rhs.getGrade() << ".";
    return (o);
}