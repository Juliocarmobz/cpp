#include <iostream>
#include "ClassZombie.hpp"

int     main(void)
{
    Zombie  testStack("julio");
    Zombie* testHeap;

    randomChump("julio2");
    testHeap = newZombie("Malloc");
    delete testHeap;
    return (0);
}
