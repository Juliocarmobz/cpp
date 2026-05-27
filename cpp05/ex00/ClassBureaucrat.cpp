#include "ClassBureaucrat.hpp"
#include <iostream>

Bureaucrat::Bureaucrat () : _name("Default"), _grade(42)
{
    std::cout << "Default constructor called" << std::endl;
    return ;
}

void    Bureaucrat::gradeValidation (void)
{
    int current_grade;
    current_grade = _grade;
    if (current_grade < 1)
        throw Bureaucrat::GradeTooHighException();
    else if (current_grade > 150)
        throw Bureaucrat::GradeTooLowException();    
    return ;
}

// need to implement validations here? if grade is too high or too low throw a exception here?
Bureaucrat::Bureaucrat (const std::string name, int grade) : _name(name), _grade(grade)
{
    // validations?
    // output operator overload needs to be used here?
    std::cout << this->_name << " created!" << std::endl;
    try
    {
        gradeValidation();
    }
    catch (Bureaucrat::GradeTooHighException & e)
    {
        std::cout << "Dumbass the grade is sooo HIGHH" << std::endl;
        //call a destructor to dealocate resources??
        //TODO print error 
    }
    catch (Bureaucrat::GradeTooLowException & e)
    {
        std::cout << "Dumbass the grade is sooo LOWW" << std::endl;
        //call a destructor to dealocate resources??
        //TODO print error 
    }
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
    std::cout << "Default " << getName() << " destructor called" << std::endl;
    return ;
}

// TODO member functions:   []incrementGrade()   []decrementGrade()

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
    try
        {
            gradeValidation();
            // if this functions thrown a error the next line must not execute, i think
            this->_grade--;
        }
        catch (Bureaucrat::GradeTooHighException & e)
        {
            std::cout << "Dumbass the grade is sooo HIGHH" << std::endl;
            //call a destructor to dealocate resources??
            //TODO print error 
        }
        catch (Bureaucrat::GradeTooLowException & e)
        {
            std::cout << "Dumbass the grade is sooo LOWW" << std::endl;
            //call a destructor to dealocate resources??
            //TODO print error 
        }
    return ;
}

void    Bureaucrat::decrementGrade (void)
{
    try
        {
            gradeValidation();
            // if this functions thrown a error the next line must not execute, i think
            this->_grade++;
        }
        catch (Bureaucrat::GradeTooHighException & e)
        {
            std::cout << "Dumbass the grade is sooo HIGHH" << std::endl;
            //call a destructor to dealocate resources??
            //TODO print error 
        }
        catch (Bureaucrat::GradeTooLowException & e)
        {
            std::cout << "Dumbass the grade is sooo LOWW" << std::endl;
            //call a destructor to dealocate resources??
            //TODO print error 
        }
    return ;
}

// output operator overload to print in the following format
std::ostream &  operator<<(std::ostream & o, Bureaucrat const & rhs)
{

    o << rhs.getName() << ", bureaucrat grade " << rhs.getGrade();
    return (o);
}