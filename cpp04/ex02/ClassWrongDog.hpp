#ifndef CLASSWRONGDOG_HPP
# define CLASSWRONGDOG_HPP

# include "ClassWrongAnimal.hpp"
# include <iostream> 

class WrongDog : public WrongAnimal
{
    
    public:
        WrongDog ();
        WrongDog (WrongDog const & src);
        ~WrongDog ();
        WrongDog & operator=(const WrongDog & rhs);
        void            makeSound() const;

};


#endif