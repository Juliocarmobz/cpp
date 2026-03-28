#include "ClassPhoneBook.hpp"
#include <iostream>

PhoneBook::PhoneBook(void)
{
    std::cout << "Inicializating" <<std::endl;
    this->index = 0;
    return ;
}

PhoneBook::~PhoneBook(void){

    std::cout << "Exiting" <<std::endl;
    return ;
}

int     PhoneBook::addContact(void)
{
    index = index % 8;
    std::cout << "adding int the index: " << index <<std::endl;  
    contacts[index].createContact();
    index++;
    return (0);
}