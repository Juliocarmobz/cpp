#ifndef FORM_HPP
# define FORM_HPP
# include <iostream>
# include <stdexcept>

class Bureaucrat;

class Form 
{
    private:
        const std::string           _name;
        bool                        _isSigned;
        const int                   _gradeToSign;
        const int                   _gradeToExecute;

    public:
        Form();
        Form (const std::string& name, int gradeToSign, int gradeToExecute);
        Form (Form const & src);
        ~Form();
        Form & operator=(const Form & rhs);

        std::string         getName (void) const;
        bool                getIsSigned (void) const;
        int                 getGradeToSign (void) const;
        int                 getGradeToExecute (void) const;

        void                beSigned(const Bureaucrat& bureaucrat);

    class GradeTooHighException : public std::exception
    {
        public:
            virtual const char* what() const throw();
    };
    
    class GradeTooLowException : public std::exception
    {
        public:
            virtual const char* what() const throw();
    };
};

std::ostream &  operator<<(std::ostream & o, Form const & rhs); //overload output operator

#endif