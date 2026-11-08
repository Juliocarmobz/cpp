#include "Intern.hpp"

Intern::Intern() {
    std::cout << "Intern created." << std::endl;
}

Intern::Intern(Intern const & src) {
    *this = src;
}

Intern::~Intern() {
    std::cout << "Intern destroyed." << std::endl;
}

Intern & Intern::operator=(const Intern & rhs) {
    (void)rhs;
    return (*this);
}

// Implementação das funções "fábrica"
AForm* Intern::makeShrubbery(std::string target) const {
    return new ShrubberyCreationForm(target);
}

AForm* Intern::makeRobotomy(std::string target) const {
    return new RobotomyRequestForm(target);
}

AForm* Intern::makePresidential(std::string target) const {
    return new PresidentialPardonForm(target);
}

AForm* Intern::makeForm(std::string formName, std::string target) const
{
    std::string formNames[] = {
        "shrubbery creation",
        "robotomy request",
        "presidential pardon"
    };

    AForm* (Intern::*formMakers[])(std::string target) const = {
        &Intern::makeShrubbery,
        &Intern::makeRobotomy,
        &Intern::makePresidential
    };

    for (int i = 0; i < 3; i++)
    {
        if (formName == formNames[i])
        {
            std::cout << "Intern creates " << formName << std::endl;
            return (this->*formMakers[i])(target);
        }
    }

    std::cout << "Error: Intern cannot create '" << formName << "' because it doesn't exist." << std::endl;
    return NULL;
}