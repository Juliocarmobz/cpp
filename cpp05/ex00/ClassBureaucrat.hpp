#ifndef CLASSBUREAUCRAT_HPP
# define CLASSBUREAUCRAT_HPP
# include <iostream>
# include <stdexcept>

class Bureaucrat
{
    private:
        std::string         _name;
        int                 grade;
    
    public:
    //orthodox canonical form here, getter and setters for name and grade and overload insertion operator
        Bureaucrat(); // default constructor
        Bureaucrat (const std::string name); // inicializated constructor
        Bureaucrat (Bureaucrat const & src); // copy constructor
        ~Bureaucrat(); // default destructor
        Bureaucrat & operator=(const Bureaucrat & rhs); //copy assignment operator

    class ExceptionClass : public std::exception
    {
        
    };
    
};

std::ostream &  operator<<(std::ostream & o, Bureaucrat const & rhs); //overload output operator

#endif