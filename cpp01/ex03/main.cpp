#include "ClassWeapon.hpp"
#include "ClassHumanA.hpp"
#include "ClassHumanB.hpp"
#include <iostream>

int     main()
{
    Weapon  bico = Weapon("AR-15 baby");

    HumanA  jsDaTorre("Js da Torre", bico);
    jsDaTorre.attack();
    bico.setType("Grock Rajda");
    jsDaTorre.attack();

    Weapon   gun = Weapon("Parafal");
    HumanB   pedrin("Pedrin");
    pedrin.setWeapon(gun);
    pedrin.attack();
    gun.setType("Big 8");
    pedrin.attack();

    // {
    // Weapon club = Weapon("crude spiked club");
    // HumanA bob("Bob", club);
    // bob.attack();
    // club.setType("some other type of club");
    // bob.attack();
    // }
    // {
    // Weapon club = Weapon("crude spiked club");
    // HumanB jim("Jim");
    // jim.setWeapon(club);
    // jim.attack();
    // club.setType("some other type of club");
    // jim.attack();
    // }
    return (0);
}