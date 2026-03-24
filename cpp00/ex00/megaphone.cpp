// #include <iostream>

// int main(void)
// {
//     std::string userInput;
//     std::getline (std::cin, userInput);

//     if (userInput == "")
//         std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
//     for (long unsigned int i = 0; i < userInput.length(); i++)
//     {
//         std::cout << (char)toupper(userInput[i]);
//     }
//     std::cout << "\n";
//     return (0);
// }

#include <iostream>

int main(int argc, char **argv)
{
    if (argc == 1)
    {
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
        return (0);
    }
    for (int i = 1; i < argc; i++)
    {
        for (int s = 0; argv[i][s]; s++)
        {
            argv[i][s] = char(toupper(argv[i][s]));
            std::cout << (char)argv[i][s];
        }
        if (i != argc - 1)
            std::cout << " ";
    }
     std::cout << "\n";
    return (0);
}