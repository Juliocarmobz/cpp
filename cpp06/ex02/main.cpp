#include <iostream>
#include <cstdlib>
#include <ctime>
#include <exception>
#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

// instantiate randomly A, B or C and returns pointer to Base
Base*   generate(void)
{
    int random = std::rand() % 3;
    if (random == 0)
    {
        std::cout << "Generated: A" << std::endl;
        return new A();
    }
    else if (random == 1)
    {
        std::cout << "Generated: B" << std::endl;
        return new B();
    }
    else
    {
        std::cout << "Generated: C" << std::endl;
        return new C();
    }
}

// print the real type of pointed object by p (A, B or C)
void    identify(Base *p)
{
    if (dynamic_cast<A*>(p))
        std::cout << "A" << std::endl;
    else if (dynamic_cast<B*>(p))
        std::cout << "B" << std::endl;
    else if (dynamic_cast<C*>(p))
        std::cout << "C" << std::endl;
    else
        std::cout << "Unkown type" <<std::endl;
}

void    identify(Base &p)
{
    try
    {
        (void)dynamic_cast<A&>(p);
        std::cout << "A" << std::endl;
        return ;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    try
    {
        (void)dynamic_cast<B&>(p);
        std::cout << "B" << std::endl;
        return ;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    try
    {
        (void)dynamic_cast<C&>(p);
        std::cout << "C" << std::endl;
        return ;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
}

int     main (void)
{
    //seed initialization for random numbers
    std::srand(static_cast<unsigned int>(std::time(NULL)));
    std::cout << "--- Test 1 ---" << std::endl;
    Base* obj1 = generate();
    std::cout << "Pointer identification: ";
    identify(obj1);
    std::cout << "Ref identification: ";
    identify(*obj1);
    delete obj1;
    std::cout << std::endl;

    std::cout << "--- Test 2 ---" << std::endl;
    Base* obj2 = generate();
    std::cout << "Pointer identification: ";
    identify(obj2);
    std::cout << "Ref identification: ";
    identify(*obj2);
    delete obj2;
    std::cout << std::endl;

    std::cout << "--- Test 3 ---" << std::endl;
    Base* obj3 = generate();
    std::cout << "Pointer identification: ";
    identify(obj3);
    std::cout << "Ref identification: ";
    identify(*obj3);
    delete obj3;
    return (0);
}