#ifndef SERIALIZER_HPP
# define SERIALIZER_HPP
# include <stdint.h> //uintptr_t type c++98
# include "Data.hpp"

class Serializer
{
    private:
        Serializer();
        Serializer(const Serializer &rhs);
        Serializer &operator=(const Serializer &rhs);
        ~Serializer();

    public:
        static uintptr_t serialize(Data *prt);
        static Data*     deserialize(uintptr_t raw);
};

#endif