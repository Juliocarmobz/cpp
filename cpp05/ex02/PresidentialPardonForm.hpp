#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

# include "AForm.hpp"
# include "Bureaucrat.hpp"


//Sign -> 72, execute 45

class PresidentialPardonForm : public AForm
{
    private:
        std::string _target;

    public:
        PresidentialPardonForm();
        PresidentialPardonForm(const std::string& target);
        PresidentialPardonForm(PresidentialPardonForm const & src);
        ~PresidentialPardonForm();
        PresidentialPardonForm & operator=(const PresidentialPardonForm & rhs);

        void execute(Bureaucrat const & executor) const;
};

#endif