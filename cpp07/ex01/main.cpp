#include <iostream>
#include <string>
#include "iter.hpp"

// func generic template to print (does not modify the element)
template <typename T>
void printElement(T const & element)
{
    std::cout << element << " ";
}

// func generic template increment (modify the element, gets &)
template <typename T>
void incrementElement(T & element)
{
    element++;
}

int main(void)
{
// TESTE 1: Array mutável (int)
    int intArray[] = {1, 2, 3, 4, 5};
    size_t const intLength = sizeof(intArray) / sizeof(intArray[0]);

    std::cout << "--- Teste com Array de Inteiros Mutavel ---" << std::endl;
    std::cout << "Original: ";
    // O compilador deduz T como 'int' e escolhe a Versão 1 ou 2 dependendo da função
    ::iter(intArray, intLength, printElement<int>); 
    std::cout << std::endl;

    std::cout << "Incrementado: ";
    ::iter(intArray, intLength, incrementElement<int>); // Chama a Versão 1
    ::iter(intArray, intLength, printElement<int>);
    std::cout << "\n\n";

    // TESTE 2: Array constante (string)
    std::string const strArray[] = {"Hello", "42", "World", "C++"};
    size_t const strLength = sizeof(strArray) / sizeof(strArray[0]);

    std::cout << "--- Teste com Array de Strings Constantes ---" << std::endl;
    std::cout << "Strings: ";
    // O compilador deduz T como 'std::string const' e DEVE escolher a Versão 2
    ::iter(strArray, strLength, printElement<std::string>);
    std::cout << std::endl;

    // Se você tentasse fazer isso abaixo, o compilador daria erro, 
    // pois o array é const e 'incrementElement' exige modificar o dado:
    // ::iter(strArray, strLength, incrementElement<std::string>);
    return (0);
}