#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "Intern.hpp"
#include <iostream>

int main(void)
{
    Intern someRandomIntern; // Instanciando o estagiário
    AForm* rrf;
    AForm* unknownForm;

    std::cout << "\n--- Teste 1: Formulário Válido ---" << std::endl;
    // Criar o form e guarda no ponteiro
    rrf = someRandomIntern.makeForm("robotomy request", "Bender");
    
    if (rrf) 
    {
        Bureaucrat benderBoss("Hermes", 1);
        benderBoss.signForm(*rrf);
        benderBoss.executeForm(*rrf);
        
        delete rrf; 
    }

    std::cout << "\n--- Teste 2: Formulário Inválido ---" << std::endl;
    unknownForm = someRandomIntern.makeForm("coffee request", "Zoidberg");
    
    if (unknownForm)
        delete unknownForm; // Nunca vai chegar aqui, mas é boa prática

    std::cout << std::endl;
    return 0;
}