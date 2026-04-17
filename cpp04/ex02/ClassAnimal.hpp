#ifndef CLASSANIMAL_HPP
# define CLASSANIMAL_HPP

# include <iostream> 

class Animal
{
    protected: 
        std::string      __type;
    
    public:
        Animal ();
        Animal (std::string type);
        Animal (Animal const & src);
        virtual ~Animal ();
        Animal & operator=(const Animal & rhs);
        std::string     const & getType() const;
        virtual void            makeSound() const = 0;

};


#endif