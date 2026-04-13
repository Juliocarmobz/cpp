#ifndef CLASSSAMPLE_HPP
# define CLASSSAMPLE_HPP
# include <iostream>

class   Sample
{

    public:
        Sample (void); //                        Canonical default constructor
        Sample (int const n);
        Sample (Sample const & src); //          Canonical copy constructor
        ~Sample (void); //                       Canonical destructor
        
        Sample & operator=(Sample const & rhs);//Canonical copy assignment operator overload

        int     getFoo(void) const;
    private:
        int     _foo;

};

std::ostream &      operator<<(std::ostream & o, Sample const & i);

#endif