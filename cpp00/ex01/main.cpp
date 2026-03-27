//Contact new_contact[1].add()   array de contatos
#include "ClassPhoneBook.hpp"
#include "ClassContact.hpp"
#include <iostream>

int main(void)
{
    //fazer um array de objetos, Contact newContact[8] e vai jogando nessa lista, mas não sei se esse contact precisa estar na classe phonebook
    int         index;
    PhoneBook   phoneBook;
    Contact     newContact[8];
    index = 0;

    while (true)
    {
        std::string     command;
        std::cout       << "Please enter one of the following COMMANDS" << std::endl;
        std::cout       << "ADD  |  SEARCH  |  EXIT" << std::endl;
        std::getline (std::cin, command);

        if (command == "ADD")
        {
            std::cout       << "Selected -> ADD" << std::endl;
            newContact[index].getInputs();
            //colocar esse novo contato no index 1 do array de contatos da lista telefonica phonebook e limpar os dados
            //if index == 7 index = index % 8?? algo assim
            index++;
        }
        else if (command == "SEARCH")
        {
            std::cout       << "Selected -> SEARCH" << std::endl;
        }
        else if (command == "EXIT")
        {
            std::cout       << "Selected -> EXIT" << std::endl;
        }
        else
            std::cout   << "Invalid COMMAND" << std::endl;
        //se o comando for ADD, entra na logica de add contato, se for SEARCH, entra na logica de procurar, se for EXIT, encerra
    }

    return (0);
}