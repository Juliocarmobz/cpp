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

        int    addContact(void);
        void   searchContact(void);

    // reponsavel por 
    // - armazenar Contact[8]
    // - controlar índice
    // - adicionar contatos
    // - mostrar contatos
};

#endif