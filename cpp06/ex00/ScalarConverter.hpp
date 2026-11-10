#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP
# include <iostream>
# include <string>
# include <limits>
# include <cstdlib>
# include <cmath>
# include <iomanip>
# include <cctype>

class ScalarConverter
{
    private:
        ScalarConverter();
        ScalarConverter(const ScalarConverter &rhs);
        ~ScalarConverter();
        ScalarConverter &operator=(const ScalarConverter &rhs);

    public:
        static void convert(const std::string &literal);
};


#endif