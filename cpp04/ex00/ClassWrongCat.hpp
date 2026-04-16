#ifndef CLASSWRONGCAT_HPP
# define CLASSWRONGCAT_HPP

# include "ClassWrongAnimal.hpp"
# include <iostream> 

class WrongCat : public WrongAnimal
{
    
    public:
        WrongCat ();
        WrongCat (WrongCat const & src);
        ~WrongCat ();
        WrongCat & operator=(const WrongCat & rhs);
        void            makeSound() const;

};


#endif