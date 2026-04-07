#include <iostream>
#include "ClassZombie.hpp"

int     main(void)
{
    Zombie*     littleHorde;
    int         hordeSize;

    hordeSize = 3;
    littleHorde  = zombieHorde(hordeSize, "lilHorde");
    for (int i = 0; i < hordeSize; i++)
        littleHorde[i].announce();
    delete [] littleHorde;
    return (0);
}
