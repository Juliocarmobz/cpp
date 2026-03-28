#include "ClassContact.hpp"
#include <iostream>

//to do funcao 

static std::string    getInputs(std::string prompt)
{

    //printar o prompt
    std::string input;
    std::getline (std::cin, input);
    while (1)
    {
        if (!td::getline (std::cin, input))
    }
    while (input.empty() || input != EOF)
        std::cout << prompt << std::endl;

    return (input);
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