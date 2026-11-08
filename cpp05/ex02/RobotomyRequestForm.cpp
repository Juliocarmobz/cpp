#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(void) : AForm("RobotomyRequestForm", 72, 45), _target("Default")
{
    return ;
}

RobotomyRequestForm::RobotomyRequestForm(const std::string& target) : AForm("RobotomyRequestForm", 72, 45), _target(target)
{
    return ;    
}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const & src) : AForm(src), _target(src._target)
{
    return ;
}

RobotomyRequestForm & RobotomyRequestForm::operator=(const RobotomyRequestForm & rhs)
{
    std::cout << "Copy assignment operator called" << std::endl;

    if (this == &rhs)
        return (*this);
    AForm::operator=(rhs);
    _target = rhs._target;
    return (*this);
}

void RobotomyRequestForm::execute(Bureaucrat const & executor) const
{
    this->checkRequirements(executor);

    std::cout << "* BZZZZZZZZZT! VRRRRRMMMM! *" << std::endl;

    if (rand() % 2 == 0)
    {
        std::cout << this->_target << " has been robotomized successfully!" << std::endl;
    }
    else
    {
        std::cout << "Robotomy on " << this->_target << " failed." << std::endl;
    }
}

RobotomyRequestForm::~RobotomyRequestForm()
{
    std::cout << "Default " << getName() << " destructor called" << std::endl;
    return ;
}
