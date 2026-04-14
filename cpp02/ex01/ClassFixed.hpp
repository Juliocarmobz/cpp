#ifndef CLASSFIXED_HPP
# define CLASSFIXED_HPP
# include <iostream>
# include <cmath>

class Fixed
{
    private:
        int                 _fixed_point_number_value;
        static const int    _number_fractional_bits = 8;
    public:
        Fixed (void);
        Fixed (const int intToConvert);
        Fixed (const float floatToConvert);
        Fixed (Fixed const & src);
        ~Fixed ();

        Fixed & operator=(Fixed const & rhs);

        int                 getRawBits (void) const;
        void                setRawBits (int const raw);
        float               toFloat (void) const;
        int                 toInt (void) const;

};

std::ostream & operator<<(std::ostream & o, Fixed const & rhs);

#endif
