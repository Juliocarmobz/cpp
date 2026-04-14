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

        Fixed               & operator=(Fixed const & rhs);

        int                 getRawBits (void) const;
        void                setRawBits (int const raw);
        float               toFloat (void) const;
        int                 toInt (void) const;

        // overload operators
        // comparision
        bool                operator>(const Fixed & rhs) const;
        bool                operator<(const Fixed & rhs) const;
        bool                operator==(const Fixed & rhs) const;
        bool                operator>=(const Fixed & rhs) const;
        bool                operator<=(const Fixed & rhs) const;
        bool                operator!=(const Fixed & rhs) const;

        // arithmetic
        Fixed               operator+(const Fixed & rhs) const;
        Fixed               operator-(const Fixed & rhs) const;
        Fixed               operator*(const Fixed & rhs) const;
        Fixed               operator/(const Fixed & rhs) const;

        // increment and decrement
        // Fixed               operator++(const Fixed);

};

std::ostream & operator<<(std::ostream & o, Fixed const & rhs);

#endif
