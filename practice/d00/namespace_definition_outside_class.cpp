#include <iostream>

class A
{
    public:
        void function();
};

void    A::function()
{
    std::cout << "function() called\n";
}

int main(void)
{
    A a;
    a.function();
    return (0);
}