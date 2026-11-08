#include "ShrubberyCreationForm.hpp"
#include "Bureaucrat.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(void) : AForm("ShrubberyCreationForm", 145, 137), _target("Default")
{
    return ;
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target) : AForm("ShrubberyCreationForm", 145, 137), _target(target)
{
    return ;    
}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const & src) : AForm(src), _target(src._target)
{
    return ;
}

ShrubberyCreationForm & ShrubberyCreationForm::operator=(const ShrubberyCreationForm & rhs)
{
    std::cout << "Copy assignment operator called" << std::endl;

    if (this == &rhs)
        return (*this);
    AForm::operator=(rhs);
    _target = rhs._target;
    return (*this);
}

void ShrubberyCreationForm::execute(Bureaucrat const & executor) const
{
    this->checkRequirements(executor); 

    std::string filename = this->_target + "_shrubbery";
    std::ofstream ofs(filename.c_str());
    if (ofs.is_open())
    {
        ofs << "   /\\   " << std::endl;
        ofs << "  /  \\  " << std::endl;
        ofs << " /____\\ " << std::endl;
        ofs << "   ||    " << std::endl;
        ofs.close();
    }
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
    std::cout << "Default " << getName() << " destructor called" << std::endl;
    return ;
}
