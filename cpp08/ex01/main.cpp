#include "Span.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>

int main() {
    std::cout << "--- TESTE BÁSICO DO SUBJECT ---" << std::endl;
    try {
        Span sp = Span(5);
        sp.addNumber(6);
        sp.addNumber(3);
        sp.addNumber(17);
        sp.addNumber(9);
        sp.addNumber(11);
        std::cout << sp.shortestSpan() << std::endl; // Esperado: 2[cite: 1]
        std::cout << sp.longestSpan() << std::endl;  // Esperado: 14[cite: 1]
    } catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
    }

    std::cout << "\n--- TESTE COM RANGE DE ITERADORES ---" << std::endl;
    try {
        Span sp(10);
        std::vector<int> numbersToAdd;
        numbersToAdd.push_back(100);
        numbersToAdd.push_back(200);
        numbersToAdd.push_back(300);
        
        sp.addNumber(10); // Adiciona um manualmente
        sp.addNumbers(numbersToAdd.begin(), numbersToAdd.end()); // Adiciona range[cite: 1]
        
        std::cout << "Shortest span (range): " << sp.shortestSpan() << std::endl;
        std::cout << "Longest span (range): " << sp.longestSpan() << std::endl;
    } catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
    }

    std::cout << "\n--- TESTE COM 15.000 NÚMEROS ALEATÓRIOS ---" << std::endl;
    try {
        Span bigSpan(15000);
        std::vector<int> randomNumbers;
        
        std::srand(std::time(NULL));
        for (int i = 0; i < 15000; i++) {
            randomNumbers.push_back(std::rand());
        }
        
        bigSpan.addNumbers(randomNumbers.begin(), randomNumbers.end());
        std::cout << "15.000 números adicionados com sucesso." << std::endl;
        std::cout << "Shortest span: " << bigSpan.shortestSpan() << std::endl;
        std::cout << "Longest span: " << bigSpan.longestSpan() << std::endl;
        
        // Testando a exceção de overflow
        std::cout << "\nTentando adicionar em uma Span cheia..." << std::endl;
        bigSpan.addNumber(42);
    } catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
    }

    std::cout << "\n--- TESTE DE EXCEÇÃO: SPAN VAZIA ---" << std::endl;
    try {
        Span emptySpan(5);
        emptySpan.addNumber(1);
        std::cout << emptySpan.shortestSpan() << std::endl; // Deve lançar exceção
    } catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}