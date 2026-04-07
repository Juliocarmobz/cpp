#ifndef  CLASSZOMBIE_HPP
# define CLASSZOMBIE_HPP
# include <iostream>

class Zombie
{
    private:
        std::string     name;

    public:
        Zombie();
        ~Zombie();

        void    announce( void );

        // todo This function creates a zombie, names it, and returns it so you can use it outside of the function scope.
        // Zombie* newZombie( std::string name );
        
        //todo This function creates a zombie, names it, and makes it announce itself.
        void randomChump( std::string name );


};



#endif