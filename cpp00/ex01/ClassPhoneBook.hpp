#ifndef CLASSPHONEBOOK_HPP
# define CLASSPHONEBOOK_HPP
# include <iostream>
# include "ClassContact.hpp"

class PhoneBook
{
    Contact     contacts[8];
    int         index;
    int         count;
    
    public:
        PhoneBook();
        ~PhoneBook();
        // void   getName();
        // void   getNickname();
        // void
        int    addContact(void); //TO DO chamar setContact
        void   searchContact(void);


    //metodo add contato
    //metodo exit (encerrar no o programa)

    // reponsavel por 
    // - armazenar Contact[8]
    // - controlar índice
    // - adicionar contatos
    // - mostrar contatos

};

#endif