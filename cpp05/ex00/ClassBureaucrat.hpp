#ifndef CLASSBUREAUCRAT_HPP
# define CLASSBUREAUCRAT_HPP
# include <iostream>
# include <stdexcept>

class Bureaucrat
{
    private:
        std::string         _name;
        int                 _grade;
    
    public:
    //orthodox canonical form here, getter and setters for name and grade and overload insertion operator
        Bureaucrat(); // default constructor
        Bureaucrat (const std::string name, int grade); // inicializated constructor
        Bureaucrat (Bureaucrat const & src); // copy constructor
        ~Bureaucrat(); // default destructor
        Bureaucrat & operator=(const Bureaucrat & rhs); //copy assignment operator
    
        void getName();
        void getGrade();
        void incrementGrade();
        void decrementGrade();


    class ExceptionClass : public std::exception
    {
        
    };
    
};

std::ostream &  operator<<(std::ostream & o, Bureaucrat const & rhs); //overload output operator

#endif