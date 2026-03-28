#ifndef CLASSPHONEBOOK_HPP
# define CLASSPHONEBOOK_HPP
# include <iostream>
# include "ClassContact.hpp"

class PhoneBook
{
    Contact     contacts[8];
    int         index;

    
    
    public:
        PhoneBook();
        ~PhoneBook();
        int    addContact(void); //TO DO chamar setContact 

    //metodo add contato
    //metodo exit (encerrar no o programa)

    // reponsavel por 
    // - armazenar Contact[8]
    // - controlar índice
    // - adicionar contatos
    // - mostrar contatos

};

#endif