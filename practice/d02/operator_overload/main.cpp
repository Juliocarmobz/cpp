#include "ClassInteger.hpp"
#include <iostream>

int     main(void)
{
    Integer a (30);
    Integer b (10);
    Integer c (0);

    std::cout << "Value of a: " << a << std::endl;
    std::cout << "Value of b: " << b << std::endl;
    
    b = Integer (12);
    std::cout << "Value of b: " << b << std::endl;

    std::cout << "Value of c: " << c << std::endl;
    c = a + b;
    std::cout << "Value of c: " << c << std::endl;

    int x = 1;
    int y = 2;
    int z = 0;
    z = y + x;
    std::cout  << "Value of simple addtion " << z << std::endl;
    return (0);
}