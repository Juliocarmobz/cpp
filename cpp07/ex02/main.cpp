#include <iostream>
#include "Array.hpp"

int main() {
    std::cout << "--- Testando Construtor Vazio ---" << std::endl;
    Array<int> emptyArray;
    std::cout << "Tamanho do array vazio: " << emptyArray.size() << std::endl;

    std::cout << "\n--- Testando Construtor com Parametro (n = 5) ---" << std::endl;
    Array<int> intArray(5);
    std::cout << "Tamanho do intArray: " << intArray.size() << std::endl;
    std::cout << "Valor inicial padrao no indice 0: " << intArray[0] << std::endl;

    std::cout << "\n--- Populando o Array ---" << std::endl;
    for (unsigned int i = 0; i < intArray.size(); i++) {
        intArray[i] = i * 10;
        std::cout << "intArray[" << i << "] = " << intArray[i] << std::endl;
    }

    std::cout << "\n--- Testando Construtor de Copia ---" << std::endl;
    Array<int> copyArray(intArray);
    copyArray[0] = 999; 
    std::cout << "Modificando copyArray[0] para 999..." << std::endl;
    std::cout << "intArray[0] original: " << intArray[0] << " (Nao deve mudar)" << std::endl;
    std::cout << "copyArray[0] modificado: " << copyArray[0] << std::endl;

    std::cout << "\n--- Testando Operador de Atribuicao ---" << std::endl;
    Array<int> assignedArray;
    assignedArray = intArray;
    assignedArray[1] = 888;
    std::cout << "Modificando assignedArray[1] para 888..." << std::endl;
    std::cout << "intArray[1] original: " << intArray[1] << " (Nao deve mudar)" << std::endl;
    std::cout << "assignedArray[1] modificado: " << assignedArray[1] << std::endl;

    std::cout << "\n--- Testando Excecao Out of Bounds ---" << std::endl;
    try {
        std::cout << "Tentando acessar intArray[5] (limite eh 4): " << std::endl;
        std::cout << intArray[5] << std::endl; // Deve lancar excecao
    } catch (std::exception & e) {
        std::cerr << e.what() << std::endl;
    }

    try {
        std::cout << "Tentando acessar emptyArray[0]: " << std::endl;
        std::cout << emptyArray[0] << std::endl; // Deve lancar excecao
    } catch (std::exception & e) {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}