#include "PmergeMe.hpp"

int main(int argc, char** argv) {
    if (argc < 2) {
        std::cerr << "Error: no sequence provided." << std::endl;
        return 1;
    }

    PmergeMe sorter;

    // Executa o parsing. Se encontrar números negativos, zeros inválidos ou strings, aborta.
    if (!sorter.parseInput(argc, argv)) {
        std::cerr << "Error" << std::endl;
        return 1;
    }

    sorter.execute();

    return 0;
}