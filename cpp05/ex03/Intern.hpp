#ifndef INTERN_HPP
# define INTERN_HPP

# include "AForm.hpp"
# include "ShrubberyCreationForm.hpp"
# include "RobotomyRequestForm.hpp"
# include "PresidentialPardonForm.hpp"
# include <iostream>
# include <string>

class Intern
{
    private:
        AForm* makeShrubbery(std::string target) const;
        AForm* makeRobotomy(std::string target) const;
        AForm* makePresidential(std::string target) const;

    public:
        Intern();
        Intern(Intern const & src);
        ~Intern();
        Intern & operator=(const Intern & rhs);

        AForm* makeForm(std::string formName, std::string target) const;
};

#endif