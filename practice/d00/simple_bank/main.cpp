#include "ClassBank.hpp"

int main(void)
{
    Bank    MyAccount;
    // Bank    *AnotherAccount = NULL;

    // MyAccount.balance = 10.0; //inacessivel pq ainda nao instanciou/inicializou
    MyAccount.inicialization("Julio", 10.0);
    // AnotherAccount->inicialization("Raphael", 8.0);

    MyAccount.deposit(5.0);
    MyAccount.consult();
    MyAccount.withdraw(7.0);
    MyAccount.consult();

    // AnotherAccount->consult();
    return (0);
}

/*
    Debugar pq quando eu uso o AnotherAccount da segfault
*/