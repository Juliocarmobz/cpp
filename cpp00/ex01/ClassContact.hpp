#ifndef CLASSCONTACT_HPP
# define CLASSCONTACT_HPP
# include <iostream>

class Contact
{
    std::string     firstName;
    std::string     lastName;
    std::string     nickName;
    std::string     phoneNumber;
    std::string     darkestSecret;

    public:
        void    createContact(void);
        void    printInfo(int i);
        void    printContact(void);

        // responsavel por
        // - guardar dados
        // - validar inputs
        // - retornar informações
};

#endif