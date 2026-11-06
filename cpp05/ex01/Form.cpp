#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::Form () : _name("Default"), _isSigned(false), _gradeToSign(42), _gradeToExecute(42)
{
    std::cout << "Default constructor called" << std::endl;
    return ;
}

Form::Form(const std::string& name, int gradeToSign, int gradeToExecute) 
    : _name(name), _isSigned(false), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute)
{
    if (_gradeToSign < 1 || _gradeToExecute < 1)
        throw Form::GradeTooHighException();
    if (_gradeToSign > 150 || _gradeToExecute > 150)
        throw Form::GradeTooLowException();
}

Form & Form::operator=(const Form & rhs)
{
    std::cout << "Copy assignment operator called" << std::endl;

    if (this == &rhs)
        return (*this);
    // this->_name = rhs._name; cannot copy _name because is const
    this->_isSigned = rhs._isSigned;
    // this->_gradeToSign = rhs._gradeToSign; cannot copy _gradeToSign because is const
    // this->_gradeToExecute = rhs._gradeToExecute; cannot copy _gradeToExecute because is const
    return (*this);
}

Form::Form (Form const & src) : _name(src._name), _isSigned(src._isSigned), _gradeToSign(src._gradeToSign), _gradeToExecute(src._gradeToExecute)
{
    std::cout << "Copy constructor called" << std::endl;
    *this = src;
    return ;
}

Form::~Form()
{
    std::cout << "Default " << getName() << " destructor called" << std::endl;
    return ;
}

void Form::beSigned(const Bureaucrat& bureaucrat)
{
    if (bureaucrat.getGrade() > this->_gradeToSign)
        throw Form::GradeTooLowException();
    this->_isSigned = true;
}

const char *Form::GradeTooHighException::what() const throw()
{
    return ("Exception: The Grade is Too High");
}

const char *Form::GradeTooLowException::what() const throw()
{
    return ("Exception: The Grade is Too Low");
}

std::string Form::getName (void) const
{
    return (this->_name);
}

bool Form::getIsSigned (void) const
{
    return (this->_isSigned);
}

int Form::getGradeToSign (void) const
{
    return (this->_gradeToSign);
}

int Form::getGradeToExecute (void) const
{
    return (this->_gradeToExecute);
}

std::ostream & operator<<(std::ostream & o, Form const & rhs)
{
    o << "Form Name: " << rhs.getName() << std::endl;
    o << "Is Signed: " << (rhs.getIsSigned() ? "Yes" : "No") << std::endl;
    o << "Grade to Sign: " << rhs.getGradeToSign() << std::endl;
    o << "Grade to Execute: " << rhs.getGradeToExecute() << std::endl;
    return (o);
}