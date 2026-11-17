#include "RPN.hpp"

RPN::RPN() {}

RPN::RPN(const RPN& other) {
    *this = other;
}

RPN& RPN::operator=(const RPN& other) {
    if (this != &other) {
        this->_stack = other._stack;
    }
    return *this;
}

RPN::~RPN() {}

void RPN::calculate(const std::string& expression) {
    for (size_t i = 0; i < expression.length(); ++i) {
        char c = expression[i];

        // Ignora espaços em branco
        if (c == ' ') continue;

        // Se for um dígito numérico (o subject garante que os números de input são menores que 10)
        if (std::isdigit(c)) {
            _stack.push(c - '0'); // Converte char para int
        } 
        // Se for um dos operadores matemáticos permitidos
        else if (c == '+' || c == '-' || c == '*' || c == '/') {
            // Um operador necessita de pelo menos 2 números na pilha
            if (_stack.size() < 2) {
                std::cerr << "Error" << std::endl;
                return;
            }

            int v2 = _stack.top(); _stack.pop();
            int v1 = _stack.top(); _stack.pop();
            int res = 0;

            if (c == '+') {
                res = v1 + v2;
            } else if (c == '-') {
                res = v1 - v2;
            } else if (c == '*') {
                res = v1 * v2;
            } else if (c == '/') {
                // Previne divisão por zero
                if (v2 == 0) {
                    std::cerr << "Error" << std::endl;
                    return;
                }
                res = v1 / v2;
            }
            // Adiciona o resultado da operação atual de volta à pilha
            _stack.push(res);
        } 
        // Se encontrar qualquer outro caractere (como letras, colchetes, etc.), dispara um erro
        else {
            std::cerr << "Error" << std::endl;
            return;
        }
    }

    // No final da string, o resultado exato e único deve sobrar na pilha
    if (_stack.size() != 1) {
        std::cerr << "Error" << std::endl;
        return;
    }

    // Exibe o resultado final na saída padrão
    std::cout << _stack.top() << std::endl;
}