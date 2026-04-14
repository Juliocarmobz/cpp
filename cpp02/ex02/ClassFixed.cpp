#include "ClassFixed.hpp"
#include <iostream>

Fixed::Fixed (void) : _fixed_point_number_value(0)
{
    std::cout << "Default constructor called" << std::endl;
    return ;
}

Fixed::Fixed (Fixed const & src)
{
    std::cout << "Copy constructor called" << std::endl;
    *this = src;
    return ;
}

Fixed::Fixed (const int intToConvert)
{
    std::cout << "Int constructor called" << std::endl;

    this->_fixed_point_number_value = intToConvert << this->_number_fractional_bits;
    return ;
}

Fixed::Fixed (const float floatToConvert)
{
    std::cout << "Float constructor called" << std::endl;
    
    this->_fixed_point_number_value = roundf(floatToConvert * (1 << this->_number_fractional_bits));
    return ;
}

Fixed::~Fixed ()
{
    std::cout << "Destructor called" << std::endl;
}

float   Fixed::toFloat (void) const
{
    return ((float)this->_fixed_point_number_value / (1 << this->_number_fractional_bits));
}

int     Fixed::toInt (void) const
{
    return (this->_fixed_point_number_value >> this->_number_fractional_bits);
}

Fixed & Fixed::operator=(Fixed const & rhs)
{
    std::cout << "Copy assignment operator called" << std::endl;

    if (this != &rhs)
        this->_fixed_point_number_value = rhs.getRawBits();
    return (*this);
}

int     Fixed::getRawBits (void) const
{
    return (this->_fixed_point_number_value);
}

void    Fixed::setRawBits (int const raw)
{
    std::cout << "setRawBits member function called" << std::endl;
    this->_fixed_point_number_value = raw;
}

std::ostream & operator<<(std::ostream & o, Fixed const & rhs)
{
    o << rhs.toFloat();
    return (o);
}

bool    Fixed::operator>(const Fixed & rhs) const
{
    if (this->_fixed_point_number_value > rhs.getRawBits())
        return (true);
    return (false);
}

bool    Fixed::operator<(const Fixed & rhs) const
{
    if (this->_fixed_point_number_value < rhs.getRawBits())
        return (true);
    return (false);
}

bool    Fixed::operator==(const Fixed & rhs) const
{
    if (this->_fixed_point_number_value == rhs.getRawBits())
        return (true);
    return (false);
}

bool    Fixed::operator>=(const Fixed & rhs) const
{
    return !(this->_fixed_point_number_value < rhs.getRawBits());
}

bool    Fixed::operator<=(const Fixed & rhs) const
{
    return !(this->_fixed_point_number_value > rhs.getRawBits());
}

bool    Fixed::operator!=(const Fixed & rhs) const
{
    return !(this->_fixed_point_number_value != rhs.getRawBits());
}

Fixed   Fixed::operator+(const Fixed & rhs) const
{
    float   result;

    result = this->toFloat() + rhs.toFloat();
    return (Fixed(result));
}

Fixed   Fixed::operator-(const Fixed & rhs) const
{
    float   result;

    result = this->toFloat() - rhs.toFloat();
    return (Fixed(result));
}

Fixed   Fixed::operator*(const Fixed & rhs) const
{
    float   result;

    result = this->toFloat() * rhs.toFloat();
    return (Fixed(result));
}

Fixed   Fixed::operator/(const Fixed & rhs) const
{
    float   result;

    result = this->toFloat() / rhs.toFloat();
    return (Fixed(result));
}
