#include "AForm.hpp"
#include "Bureaucrat.hpp"

AForm::AForm () : _name("Default"), _isSigned(false), _gradeToSign(42), _gradeToExecute(42)
{
    std::cout << "Default constructor called" << std::endl;
    return ;
}

AForm::AForm(const std::string& name, int gradeToSign, int gradeToExecute) 
    : _name(name), _isSigned(false), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute)
{
    if (_gradeToSign < 1 || _gradeToExecute < 1)
        throw AForm::GradeTooHighException();
    if (_gradeToSign > 150 || _gradeToExecute > 150)
        throw AForm::GradeTooLowException();
}

void AForm::checkRequirements(Bureaucrat const & executor) const
{
    if (!this->getIsSigned())
        throw FormNotSignedException();
    if (executor.getGrade() > this->getGradeToExecute())
        throw AForm::GradeTooLowException();
}

AForm & AForm::operator=(const AForm & rhs)
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

AForm::AForm (AForm const & src) : _name(src._name), _isSigned(src._isSigned), _gradeToSign(src._gradeToSign), _gradeToExecute(src._gradeToExecute)
{
    std::cout << "Copy constructor called" << std::endl;
    *this = src;
    return ;
}

AForm::~AForm()
{
    std::cout << "Default " << getName() << " destructor called" << std::endl;
    return ;
}

void AForm::beSigned(const Bureaucrat& bureaucrat)
{
    if (bureaucrat.getGrade() > this->_gradeToSign)
        throw AForm::GradeTooLowException();
    this->_isSigned = true;
}

const char *AForm::GradeTooHighException::what() const throw()
{
    return ("Exception: The Grade is Too High");
}

const char *AForm::GradeTooLowException::what() const throw()
{
    return ("Exception: The Grade is Too Low");
}

const char *AForm::FormNotSignedException::what() const throw()
{
    return ("Exception: Form not Signed");
}

std::string AForm::getName (void) const
{
    return (this->_name);
}

bool AForm::getIsSigned (void) const
{
    return (this->_isSigned);
}

int AForm::getGradeToSign (void) const
{
    return (this->_gradeToSign);
}

int AForm::getGradeToExecute (void) const
{
    return (this->_gradeToExecute);
}

std::ostream & operator<<(std::ostream & o, AForm const & rhs)
{
    o << "AForm Name: " << rhs.getName() << std::endl;
    o << "Is Signed: " << (rhs.getIsSigned() ? "Yes" : "No") << std::endl;
    o << "Grade to Sign: " << rhs.getGradeToSign() << std::endl;
    o << "Grade to Execute: " << rhs.getGradeToExecute() << std::endl;
    return (o);
}