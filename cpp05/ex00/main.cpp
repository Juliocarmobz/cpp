#include "Bureaucrat.hpp"
#include <iostream>

int     main(void)
{
    // Bureaucrat edmilson("Edmilson", 30);
    // std::cout << edmilson << std::endl;

    // Bureaucrat edmilson_copy;
    // edmilson_copy = edmilson;
    // std::cout << edmilson_copy << std::endl;
    try
    {
        Bureaucrat edmilson2("Edmilson2", -30);
        std::cout << edmilson2 << std::endl;
        // Bureaucrat edmilson3("Edmilson3", 1);
        // edmilson3.incrementGrade();
        // std::cout << edmilson3 << std::endl;
        // Bureaucrat edmilson4("Edmilson4", 150);
        // edmilson4.decrementGrade();
        // std::cout << edmilson4 << std::endl;
    }
    catch (Bureaucrat::GradeTooHighException & e)
    {
        std::cout << "Dumbass the grade is sooo HIGHH" << std::endl;
        std::cout << e.what() << std::endl;
    }
    catch (Bureaucrat::GradeTooLowException & e)
    {
        std::cout << "Dumbass the grade is sooo LOWW" << std::endl;
        std::cout << e.what() << std::endl;
    }

    return (0);
}