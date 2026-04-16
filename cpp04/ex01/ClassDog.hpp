#ifndef CLASSDOG_HPP
# define CLASSDOG_HPP

# include "ClassAnimal.hpp"
# include <iostream> 

class Dog : public Animal
{
    
    public:
        Dog ();
        Dog (Dog const & src);
        ~Dog ();
        Dog & operator=(const Dog & rhs);
        void            makeSound() const;

};


#endif