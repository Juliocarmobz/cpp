#include "ClassBank.hpp"

void    Bank::inicialization(std::string n, float v)
{
    name = n;
    balance = v;
    if (balance < 0)
        std::cout << "Error in the account inicialization" << std::endl;

}

void    Bank::deposit(float value)
{
    balance = balance + value;
}

void    Bank::consult()
{
    std::cout << "Client: " << name << std::endl;
    std::cout << "Current Balance: " << balance << std::endl;
    std::cout << "Account number: " << number << std::endl;  //acho que esse numero nao eh inicializado em nenhum lugar

}

int     Bank::withdraw(float value)
{
    if (balance < value)
        return (0);
    else
    {
        balance = balance - value;
        return 1;
    }
}


/*
        void    inicialization(std::string n, float v);
        int     withdraw(float value);
        void    deposit(float value);
        void    consult();
*/