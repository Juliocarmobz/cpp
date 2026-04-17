#ifndef CLASSBRAIN_HPP
# define CLASSBRAIN_HPP

# include <iostream> 

class Brain
{
    private:
        std::string ideas[100];
    public:
        Brain ();
        Brain (Brain const & src);
        Brain & operator=(const Brain & rhs);
        ~Brain ();
};


#endif