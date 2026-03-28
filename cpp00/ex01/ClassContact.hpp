#ifndef CLASSCONTACT_HPP
# define CLASSCONTACT_HPP
# include <iostream>

class Contact
{
    //The contact fields are: first name, last name, nickname, phone number, and darkest secret
    std::string     firstName;
    std::string     lastName;
    std::string     nickName;
    std::string     phoneNumber;
    std::string     darkestSecret;

    public:
        // Contact();
        // ~Contact();
        //fazer getters and setters aqui (para poder usar contacts[i].setName() ou contacts[i].getName())

        void    createContact(void);

        
        //normalizeInputs(firstName, lastName, etc etc)
        //metodos de manipular e verificar os inputs e outputs
        //precisa fazer um contrutor e destrutor??
        
        // responsavel por
        // - guardar dados
        // - validar inputs
        // - retornar informações


        
};

#endif