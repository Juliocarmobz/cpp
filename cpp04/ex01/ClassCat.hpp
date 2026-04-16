#ifndef CLASSCAT_HPP
# define CLASSCAT_HPP

# include "ClassAnimal.hpp"
# include <iostream> 

class Cat : public Animal
{
    
    public:
        Cat ();
        Cat (Cat const & src);
        ~Cat ();
        Cat & operator=(const Cat & rhs);
        void            makeSound() const;

};


#endif