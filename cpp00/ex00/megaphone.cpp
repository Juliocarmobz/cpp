#include <iostream>

int main(void)
{
    std::string userInput;
    std::cin >> userInput;
    // std::string userInput = "";

    if (userInput == "")
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << '\n';
    // for (char &c : userInput)
    // {
    //     c = std::toupper(c);
    // }
    // std::cout << userInput << '\n';
    return (0);
}