#ifndef CLASSBANK_HPP
# define CLASSBANK_HPP
# include <iostream>

class   Bank{

    std::string name;    //sao atributos privados por padrao
    int         number;
    float       balance;

    public:
        void    inicialization(std::string n, float v);
        int     withdraw(float value);
        void    deposit(float value);
        void    consult();
};

#endif