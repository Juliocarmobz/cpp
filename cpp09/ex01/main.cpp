#include "RPN.hpp"

int main(int argc, char **argv) {
    // O programa deve receber exatamente 1 argumento além do próprio nome do executável
    if (argc != 2) {
        std::cerr << "Error" << std::endl;
        return 1;
    }

    RPN rpn;
    // O argumento é a expressão matemática invertida passada por parâmetro (ex: "8 9 * 9 -")
    rpn.calculate(argv[1]);

    return 0;
}