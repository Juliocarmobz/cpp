#include "ClassPhoneBook.hpp"
#include <iostream>
#include <iomanip>
#include <sstream>
#include <cstdlib>

PhoneBook::PhoneBook(void)
{
    std::cout << "Inicializating" <<std::endl;
    this->index = 0;
    this->count = 0;
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
    if (count < 8)
        count++;
    return (0);
}

void    PhoneBook::searchContact(void)
{
    std::string selectedIndex;
    if (count == 0)
    {
        std::cout << "There is no contact available" << std::endl;
        return ;
    }
    int i = 0;
    std::cout << "| INDEX  |FIRST NAME| LAST NAME| NICKNAME |" << std::endl; 
    while (i < count)
    {
        contacts[i].printInfo(i);
        i++;
    }
    std::cout << "Select index: ";
    if (!std::getline (std::cin, selectedIndex))
        exit(1);
    while (selectedIndex.empty())
    {
        std::cout << "Select index: ";
        if (!std::getline (std::cin, selectedIndex))
            exit (1);
    }
    std::stringstream ss(selectedIndex);
    if (!(ss >> i) || !(ss.eof()) || (i < 0) || i >= count)
    {
        std::cout << "worng input" << std::endl;    
        return ;
    }
    contacts[i].printContact();
}
