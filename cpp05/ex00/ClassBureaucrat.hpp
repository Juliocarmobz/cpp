#ifndef CLASSBUREAUCRAT_HPP
# define CLASSBUREAUCRAT_HPP
# include <iostream>
# include <stdexcept>

class Bureaucrat
{
    private:
        const std::string           _name;
        int                         _grade;
    
    public:
        Bureaucrat();
        Bureaucrat (const std::string& name, int grade);
        Bureaucrat (Bureaucrat const & src);
        ~Bureaucrat();
        Bureaucrat & operator=(const Bureaucrat & rhs);
    
        std::string         getName (void) const;
        int                 getGrade (void) const;
        void                incrementGrade();
        void                decrementGrade();
        void                gradeValidation (int grade_verfication);


    class GradeTooHighException : public std::exception
    {
        public:
            virtual const char* what() const throw()
            {
                return ("Exception: The Grade is Too High");
            }
    };
    
    class GradeTooLowException : public std::exception
    {
        public:
            virtual const char* what() const throw()
            {
                return ("Exception: The Grade is Too Low");
            }
    };
};

std::ostream &  operator<<(std::ostream & o, Bureaucrat const & rhs); //overload output operator

#endif