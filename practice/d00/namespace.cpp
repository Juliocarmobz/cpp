#include <iostream>
using   namespace std;

/*
*/

namespace MyNamespace
{
    int x = 42;
}

int main(void)
{
    cout << MyNamespace::x;
    cout << "\n";
    return (0);
}