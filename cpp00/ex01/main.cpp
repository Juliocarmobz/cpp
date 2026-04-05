#include "ClassPhoneBook.hpp"
#include "ClassContact.hpp"
#include <iostream>
#include <cstdlib>

int main(void)
{
    PhoneBook       phoneBook;
    std::string     command;

    while (true)
    {
        command = "";
        std::cout       << "Please enter one of the following COMMANDS" << std::endl;
        std::cout       << "ADD  |  SEARCH  |  EXIT" << std::endl;
        if (!std::getline (std::cin, command))
            exit(1);

        if (command == "ADD")
        {
            std::cout       << "Selected -> ADD" << std::endl;
            phoneBook.addContact();
        }
        else if (command == "SEARCH")
        {
            std::cout       << "Selected -> SEARCH" << std::endl;
            phoneBook.searchContact();
        }
        else if (command == "EXIT")
        {
            std::cout       << "Selected -> EXIT" << std::endl;
            return (0);
        }
        else
            std::cout   << "Invalid COMMAND" << std::endl;
    }
    return (0);
}
