#include "ClassAnimal.hpp"
#include "ClassCat.hpp"
#include "ClassDog.hpp"
#include <iostream>

int main()
{
    const Animal* j = new Dog();
    const Animal* i = new Cat();

    std::cout << j->getType() << std::endl;
    std::cout << i->getType() << std::endl;

    j->makeSound();
    i->makeSound();

    delete j;
    delete i;

    return (0);
}