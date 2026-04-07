#ifndef  CLASSZOMBIE_HPP
# define CLASSZOMBIE_HPP
# include <iostream>

class Zombie
{
    private:
        std::string     _name;

    public:
        void setName( std::string name );
        Zombie();
        ~Zombie();

        void    announce( void );
    };

    Zombie* zombieHorde( int N, std::string name );

#endif