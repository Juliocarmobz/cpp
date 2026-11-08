#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <iostream>

int main(void)
{
    // seed to funcion rand() for RobotomyRequestForm
    srand(time(NULL));

    std::cout << "\n=============================================" << std::endl;
    std::cout << "          TESTING SHRUBBERY CREATION          " << std::endl;
    std::cout << "=============================================\n" << std::endl;
    try
    {
        Bureaucrat edmilson("Edmilson", 137); // Nota suficiente para executar (req: 137)
        Bureaucrat estagiario("Estagiario", 145); // Nota só para assinar (req: 145)
        ShrubberyCreationForm shrubbery("Zuno");
        
        std::cout << shrubbery << std::endl;
        
        // Estagiario assina o formulário
        estagiario.signForm(shrubbery);
        
        // Estagiário não tem nota para executar
        estagiario.executeForm(shrubbery);
        
        // Edmilson executa o formulário e gera a árvore ascii no diretório
        edmilson.executeForm(shrubbery);
    }
    catch (std::exception & e)
    {
        std::cout << "Erro inesperado: " << e.what() << std::endl;
    }

    std::cout << "\n=============================================" << std::endl;
    std::cout << "          TESTING ROBOTOMY REQUEST            " << std::endl;
    std::cout << "=============================================\n" << std::endl;
    try
    {
        Bureaucrat edmilson("Edmilson", 45); // Nota suficiente para executar (req: 45)
        RobotomyRequestForm robotomy("Bender");

        // Edmilson tenta executar antes de assinar (deve falhar e cair no checkRequirements)
        edmilson.executeForm(robotomy);
        
        // Edmilson assina e depois executa
        edmilson.signForm(robotomy);
        edmilson.executeForm(robotomy);
        edmilson.executeForm(robotomy); // Executando várias vezes para ver os 50% de chance
        edmilson.executeForm(robotomy);
        edmilson.executeForm(robotomy);
    }
    catch (std::exception & e)
    {
        std::cout << "Erro inesperado: " << e.what() << std::endl;
    }

    std::cout << "\n=============================================" << std::endl;
    std::cout << "        TESTING PRESIDENTIAL PARDON           " << std::endl;
    std::cout << "=============================================\n" << std::endl;
    try
    {
        Bureaucrat edmilson("Edmilson", 1); // Burocrata mais forte de todos (req: 5)
        Bureaucrat estagiario("Estagiario", 25); // Nota só para assinar (req: 25)
        PresidentialPardonForm pardon("Ford Prefect");

        // Estagiario assina
        estagiario.signForm(pardon);
        
        // Edmilson executa
        edmilson.executeForm(pardon);

        // Estagiario tenta executar
        estagiario.executeForm(pardon);
    }
    catch (std::exception & e)
    {
        std::cout << "Erro inesperado: " << e.what() << std::endl;
    }

    return 0;
}