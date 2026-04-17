#ifndef CLASSDOG_HPP
# define CLASSDOG_HPP

# include "ClassAnimal.hpp"
# include <iostream>
# include "ClassBrain.hpp"

class Dog : public Animal
{
    private:
        Brain   *_brain;
    public:
        Dog ();
        Dog (Dog const & src);
        ~Dog ();
        Dog & operator=(const Dog & rhs);
        void            makeSound() const;
        Brain*          getBrain() const;

};


#endif