#ifndef CLASSFIXED_HPP
# define CLASSFIXED_HPP
class Fixed
{
    private:
        int                 fixed_point_number_value;
        static const int    number_fractional_bits;
    public:
        Fixed();
        //copy constructor
        //copy assignment operator overload
        ~Fixed();
        int                 getRawBits (void) const;
        void                setRawBits (int const raw);
};

#endif
