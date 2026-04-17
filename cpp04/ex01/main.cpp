#include "ClassAnimal.hpp"
#include "ClassCat.hpp"
#include "ClassDog.hpp"
#include <iostream>

int main()
{
    const int size = 10;
    Animal* animals[size];

    std::cout << "\n---- Creating animals ----\n" << std::endl;

    for (int i = 0; i < size / 2; i++)
        animals[i] = new Dog();

    for (int i = size / 2; i < size; i++)
        animals[i] = new Cat();

    std::cout << "\n---- Testing sounds ----\n" << std::endl;

    for (int i = 0; i < size; i++)
        animals[i]->makeSound();

    std::cout << "\n---- Deleting animals ----\n" << std::endl;

    for (int i = 0; i < size; i++)
        delete animals[i];

    // Dog original;
    // Dog copy = original;
    return (0);
}