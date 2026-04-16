#include "ClassAnimal.hpp"
#include "ClassCat.hpp"
#include "ClassDog.hpp"
#include "ClassWrongAnimal.hpp"
#include "ClassWrongCat.hpp"
#include "ClassWrongDog.hpp"
#include <iostream>

int main()
{
    const Animal* meta = new Animal();
    const Animal* j = new Dog();
    const Animal* i = new Cat();
    std::cout << j->getType() << " " << std::endl;
    std::cout << i->getType() << " " << std::endl;
    i->makeSound(); //will output the cat sound!
    j->makeSound();
    meta->makeSound();

    delete j;
    delete i;
    delete meta;

    std::cout << "-----------WrongClasses-----------" << std::endl;
    const WrongAnimal* meta2 = new WrongAnimal();
    const WrongAnimal* i2 = new WrongCat();

    std::cout << i2->getType() << std::endl;

    i2->makeSound();

    delete i2;
    delete meta2;

    return 0;
}