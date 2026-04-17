#ifndef CLASSCAT_HPP
# define CLASSCAT_HPP

# include "ClassAnimal.hpp"
# include <iostream> 
# include "ClassBrain.hpp"

class Cat : public Animal
{
    private:
        Brain   *_brain;
    public:
        Cat ();
        Cat (Cat const & src);
        ~Cat ();
        Cat & operator=(const Cat & rhs);
        void            makeSound() const;
        Brain*          getBrain() const;

};


#endif