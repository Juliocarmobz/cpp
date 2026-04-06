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

        Zombie* newZombie( std::string name );
        // todo This function creates a zombie, names it, and returns it so you can use it outside of the function scope.
        
        void randomChump( std::string name );
        //This function creates a zombie, names it, and makes it announce itself.


};



#endif