#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <iostream>

int     main(void)
{
    std::cout << "--- TESTE 1: Construcao Valida ---" << std::endl;
    try {
        Form f1("Formulario A", 50, 25);
        std::cout << f1 << std::endl;
    } catch (std::exception & e) {
        std::cout << "Erro: " << e.what() << std::endl;
    }

    std::cout << "\n--- TESTE 2: Construcao Invalida (Nota de assinatura muito alta) ---" << std::endl;
    try {
        Form f2("Formulario B", 0, 50); // Deve falhar, 1 é o limite
    } catch (std::exception & e) {
        std::cout << "Excecao capturada: " << e.what() << std::endl;
    }

    std::cout << "\n--- TESTE 3: Construcao Invalida (Nota de execucao muito baixa) ---" << std::endl;
    try {
        Form f3("Formulario C", 50, 200); // Deve falhar, 150 é o limite[cite: 1]
    } catch (std::exception & e) {
        std::cout << "Excecao capturada: " << e.what() << std::endl;
    }

    std::cout << "\n--- TESTE 4: Burocrata com nota suficiente assinando ---" << std::endl;
    try {
        Bureaucrat b1("Edmilson", 30);
        Form f4("Alvarar", 50, 50); // Nota 50 exigida. Edmilson tem 30 (melhor que 50)[cite: 1]
        
        std::cout << "Antes: " << f4.getIsSigned() << std::endl;
        b1.signForm(f4); // Bureaucrat tenta assinar
        std::cout << "Depois: " << f4.getIsSigned() << std::endl;
    } catch (std::exception & e) {
        std::cout << "Erro inesperado: " << e.what() << std::endl;
    }

    std::cout << "\n--- TESTE 5: Burocrata sem nota suficiente tentando assinar ---" << std::endl;
    try {
        Bureaucrat b2("Estagiario", 100);
        Form f5("Contrato", 50, 50); // Nota 50 exigida. Estagiario tem 100 (pior que 50)
        
        b2.signForm(f5); // Bureaucrat tenta assinar, deve printar a falha
    } catch (std::exception & e) {
        std::cout << "Erro inesperado: " << e.what() << std::endl;
    }
    return (0);
}