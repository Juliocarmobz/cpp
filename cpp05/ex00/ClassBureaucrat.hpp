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
    
        std::string         getName (void) const;
        int                 getGrade (void) const;
        void                incrementGrade();
        void                decrementGrade();
        void                gradeValidation (void);


    class GradeTooHighException : public std::exception
    {
        public:
            virtual const char* what() const throw()
            {
                return ("The Grade is Too High");
            }
    };
    
    class GradeTooLowException : public std::exception
    {
        public:
            virtual const char* what() const throw()
            {
                return ("The Grade is Too Low");
            }
    };
};

std::ostream &  operator<<(std::ostream & o, Bureaucrat const & rhs); //overload output operator

#endif