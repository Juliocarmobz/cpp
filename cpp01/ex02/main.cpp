#include <iostream>

int     main(void)
{
    std::string     stringVariable = "HI THIS IS BRAIN";
    
    std::string*    stringPTR = &stringVariable;
    std::string&    stringREF = stringVariable;

    std::cout << "memory address of the string variable -> " << &stringVariable << std::endl;
    std::cout << "memory address held by stringPTR      -> " << stringPTR << std::endl;
    std::cout << "memory address held by stringREF      -> " << &stringREF << std::endl;

    std::cout << "value of the string variable  -> " << stringVariable << std::endl;
    std::cout << "value pointed to by stringPTR -> " << *stringPTR << std::endl;
    std::cout << "value pointed to by stringREF -> " << stringREF << std::endl;
    return (0);
}