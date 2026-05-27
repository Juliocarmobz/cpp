#include "ClassBureaucrat.hpp"
#include <iostream>

int     main(void)
{
    // try catch blocks needs to be here
    Bureaucrat edmilson("Edmilson", 30);
    std::cout << edmilson << std::endl;

    Bureaucrat edmilson2("Edmilson2", -30);
    std::cout << edmilson2 << std::endl;

    Bureaucrat edmilson3("Edmilson", 1);
    edmilson3.incrementGrade();
    std::cout << edmilson3 << std::endl;

    Bureaucrat edmilson4("Edmilson", 150);
    edmilson4.decrementGrade();
    std::cout << edmilson4 << std::endl;

    return (0);
}