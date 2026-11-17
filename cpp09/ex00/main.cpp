#include "BitcoinExchange.hpp"

int main(int argc, char **argv) {
    if (argc != 2) {
        std::cerr << "Error: could not open file." << std::endl;
        return 1;
    }

    // Inicializa o objeto chama o parse do data.csv no construtor
    BitcoinExchange btc;
    
    // Processa o arquivo passado como argumento
    btc.processInput(argv[1]);

    return 0;
}