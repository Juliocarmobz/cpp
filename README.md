# C++ - Module 00
### Namespaces, classes, member functions, stdio streams,initialization lists, static, const, and some other basic stuf

## Things about cpp projects
* Will follow de C++98 standards 
* flags `-Wall -Wextra -Werror -std=c++98`
* Exercise directories will be named like ex00, ex01 ...
* Classes names must be in **UpperCamelCase**
* Files containing class code will always be named according to the class name. For instance: ClassName.hpp/ClassName.h, ClassName.cpp, or ClassName.tpp.
* Every output must be at stdout and followed by a newline
* **Goodbye Norminette**
*  C++11 (and derived forms) and Boost libraries are forbidden. The following functions are forbidden too: **printf(), alloc() and free().**
*  namespace <ns_name> and friend keywords are forbidden.
* STL only in Modules 08 and 09. That means: no Containers (vector/list/map, and so forth) and no Algorithms (anything that requires including the <algorithm> header) until then.
## Design requirements
* When use **new** to allocate memory, remember to free them to avoid memory leaks.
*  Module 02 to Module 09, classes must be designed in the Orthodox Canonical Form, except when explicitly stated otherwise **I DON'T KNOW**
* Any function implementation put in a header file (except for function templates) means 0 to the exercise. **DON'T UNDERSTAND**
* Must avoid the double inclusion in headerfiles using the **include guards**
* Remember to check the examples of the exercises
* Makefile rules are the same of the C exercises  

## References
### Intra CPP Bootcamp videos, studies will be at the practice folder