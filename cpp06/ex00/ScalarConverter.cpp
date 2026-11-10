#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter()
{
    std::cout << "Default constructor called" << std::endl;
    return ;
}

ScalarConverter::ScalarConverter(const ScalarConverter &rhs)
{
    std::cout << "Copy constructor called" << std::endl;
    *this = rhs;
    return ;
}

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &rhs)
{
    std::cout << "Copy assignment operator called" << std::endl;

    if (this == &rhs)
        return (*this);
    return (*this);
}

ScalarConverter::~ScalarConverter()
{
    std::cout << "Default destructor called" << std::endl;
    return ;
}

static bool isPseudoLiteral(const std::string &literal)
{
    return (literal == "-inff" || literal == "+inff" || literal == "nanf" ||
            literal == "-inf"  || literal == "+inf"  || literal == "nan");
}

static bool isChar(const std::string &literal)
{
    // if char lenth 1 and it is not a numeric digit (ex.: 'c', '*')
    if (literal.length() == 1 && !std::isdigit(literal[0]))
    {
        return true;
    }
    return false;
}

static bool isInt(const std::string &literal)
{
    size_t i = 0;
    if (literal[i] == '-' || literal[i] == '+')
        i++;
    if (i == literal.length())
        return (false);
    while (i < literal.length())
    {
        if (!std::isdigit(literal[i])) 
            return (false);
        i++;
    }
    return (true);
}

static bool isFloat(const std::string &literal)
{
    size_t  i = 0;
    bool    hasDot = false;

    if (literal[i] == '-' || literal[i] == '+')
        i++;
    while (i < literal.length())
    {
        if (literal[i] == '.')
        {
            if (hasDot)
                return (false);
            hasDot = true;
        }
        else if (literal[i] == 'f' && i == literal.length() - 1)
            return (hasDot); //it should terminate with 'f' and must have '.'
        else if (!std::isdigit(literal[i]))
            return (false);
        i++;
    }
    return (false);

}

static bool isDouble(const std::string &literal)
{
    size_t  i = 0;
    bool    hasDot = false;

    if (literal[i] == '-' || literal[i] == '+')
        i++;
    while (i < literal.length())
    {
        if (literal[i] == '.')
        {
            if (hasDot)
                return (false);
            hasDot = true;
        }
        else if (!std::isdigit(literal[i]))
            return (false);
        i++;
    }
    return hasDot; //it must have '.' but not terminated with 'f'
}

static void printConversions(char c_val, long i_val, float f_val, double d_val, bool impossibleInt = false)
{
    // print char
    if (impossibleInt || i_val < std::numeric_limits<char>::min() || i_val > std::numeric_limits<char>::max())
    {
        std::cout << "char: impossible" << std::endl;
    }
    else if (!std::isprint(c_val)) //not visible conversion
    {
        std::cout << "char: Non displayable" << std::endl;
    }
    else
    {
        std::cout << "char: '" << c_val << "'" << std::endl;
    }

    //print int
    if (impossibleInt || d_val < std::numeric_limits<int>::min() || d_val > std::numeric_limits<int>::max())
    {
        std::cout << "int: impossible" << std::endl;
    }
    else
    {
        std::cout << "int: " << static_cast<int>(i_val) << std::endl;
    }

    // float and doule get precision (.0) when is integer
    std::cout << std::fixed << std::setprecision(1);

    // print float
    std::cout << "float: " << f_val << "f" << std::endl;

    // print double
    std::cout << "double: " << d_val << std::endl;
}

void ScalarConverter::convert(const std::string& literal) 
{
    if (isPseudoLiteral(literal))
    {
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
        if (literal == "nan" || literal == "nanf")
        {
            std::cout << "float: nanf" << std::endl;
            std::cout << "double: nan" << std::endl;
        }
        else if (literal == "+inf" || literal == "+inff")
        {
            std::cout << "float: +inff" << std::endl;
            std::cout << "double: +inf" << std::endl;
        }
        else
        {
            std::cout << "float: -inff" << std::endl;
            std::cout << "double: -inf" << std::endl;            
        }
        return ;
    }

    if(isChar(literal))
    {
        char    c_val = literal[0];
        long    i_val = static_cast<long>(c_val);
        float   f_val = static_cast<float>(c_val);
        double  d_val = static_cast<double>(c_val);
        printConversions(c_val, i_val, f_val, d_val);
    }
    else if (isInt(literal))
    {
        long    i_val = std::strtol(literal.c_str(), NULL, 10);
        char    c_val = static_cast<char>(i_val);
        float   f_val = static_cast<float>(i_val);
        double  d_val = static_cast<double>(i_val);
        printConversions(c_val, i_val, f_val, d_val);
    }
    else if (isFloat(literal))
    {
        double  temp_d = std::strtod(literal.c_str(), NULL);
        float   f_val = static_cast<float>(temp_d);
        char    c_val = static_cast<char>(f_val);
        int     i_val = static_cast<long>(f_val);
        double  d_val = static_cast<double>(f_val);
        printConversions(c_val, i_val, f_val, d_val);  
    }
    else if (isDouble(literal))
    {
        double  d_val = std::strtod(literal.c_str(), NULL);
        char    c_val = static_cast<char>(d_val);
        int     i_val = static_cast<long>(d_val);
        float   f_val = static_cast<float>(d_val);
        printConversions(c_val, i_val, f_val, d_val);
    }
    else
        std::cout << "Error: Literal format not recognized or impossible" << std::endl;
}