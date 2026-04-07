#include <iostream>
#include "ClassZombie.hpp"


int     main(void)
{
    Zombie  testStack("julio");
    Zombie* testHeap;

    testStack.randomChump("julio2");
    testHeap = testStack.newZombie("Malloc");
    testHeap->randomChump("MallocStack");
    delete testHeap;
    return (0);
}