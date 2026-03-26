#include "ClassContact.hpp"
#include <iostream>

int     Contact::getInputs(void)
{
    while (firstName == "")
    {
        std::cout << "Insert | First Name: " ;
        std::getline (std::cin, firstName);
        std::cout << "your input is: " << firstName << std::endl;
    }
    while (lastName == "")
    {
        std::cout << "Insert | Last Name: " ;
        std::getline (std::cin, lastName);
        std::cout << "your input is: " << lastName << std::endl;
    }
    while (nickName == "")
    {
        std::cout << "Insert | Nickname: " ;
        std::getline (std::cin, nickName);
        std::cout << "your input is: " << nickName << std::endl;
    }
    while (phoneNumber == "")
    {
        std::cout << "Insert | Phone Number: " ;
        std::getline (std::cin, phoneNumber);
        std::cout << "your input is: " << phoneNumber << std::endl;
    }
    while (darkestSecret == "")
    {
        std::cout << "Insert | Darkest Secrect: " ;
        std::getline (std::cin, darkestSecret);
        std::cout << "your input is: " << darkestSecret << std::endl;
    }
    return (0);
}