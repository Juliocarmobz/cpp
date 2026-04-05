#include "ClassContact.hpp"
#include <iostream>
#include <cstdlib>
#include <iomanip>

static std::string    getInputs(std::string prompt)
{
    std::cout << prompt << std::endl;
    std::string input;
    while (1)
    {
        if (!std::getline (std::cin, input))
            exit(1);
        if (!input.empty())
            return input;
    }
    return (input);
}

static void    transformPrint(std::string unformated)
{
    if (unformated.length() < 10)
        std::cout << std::setw(10) << unformated << "|";
    else
        std::cout << unformated.substr(0, 9) << ".|";
}

void     Contact::printContact(void)
{
    std::cout << "First name: " << firstName << std::endl;
    std::cout << "Last name: " << lastName << std::endl;
    std::cout << "Nickname: " << nickName << std::endl;
    std::cout << "Phone number: " << phoneNumber << std::endl;
    std::cout << "Darkest secrect: " << darkestSecret << std::endl;


    std::cout << std::endl;
}

void     Contact::printInfo(int i)
{
    std::cout << std::setw(9) << i << "|";
    transformPrint(firstName);
    transformPrint(lastName);
    transformPrint(nickName);

    std::cout << std::endl;
}

void     Contact::createContact(void)
{
    firstName = getInputs("Insert | First Name: ");
    lastName = getInputs("Insert | Last Name: ");
    nickName = getInputs("Insert | Nickname: ");
    phoneNumber = getInputs("Insert | Phone Number: ");
    darkestSecret = getInputs("Insert | Darkest Secrect: ");

    return ;
}
