#ifndef CLASSWRONGANIMAL_HPP
# define CLASSWRONGANIMAL_HPP

# include <iostream> 

class WrongAnimal
{
    protected: 
        std::string      __type;

    public:
        WrongAnimal ();
        WrongAnimal (std::string type);
        WrongAnimal (WrongAnimal const & src);
        ~WrongAnimal ();
        WrongAnimal & operator=(const WrongAnimal & rhs);
        std::string     const & getType() const;
        void            makeSound() const;

};


#endif