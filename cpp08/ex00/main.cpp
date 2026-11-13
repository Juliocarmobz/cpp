#include <iostream>
#include <vector>
#include <list>
#include "easyfind.hpp"

int main(void)
{
    std::cout << "--- STD::VECTOR ---" << std::endl;
    std::vector<int> vec;

    vec.push_back(10);
    vec.push_back(20);
    vec.push_back(30);
    vec.push_back(42);
    vec.push_back(75);

    try
    {
        std::cout << "searching 30 in vector..." << std::endl;
        std::vector<int>::iterator it = easyfind(vec, 30);
        std::cout << "found value..." << *it << std::endl;
        
        std::cout << "searching 69 in vector..." << std::endl;
        easyfind(vec, 69);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }

    std::cout << "--- STD::LIST ---" << std::endl;
    std::list<int> lst;

    lst.push_back(10);
    lst.push_back(20);
    lst.push_back(30);
    lst.push_back(42);
    lst.push_back(75);

    try
    {
        std::cout << "searching 30 in list..." << std::endl;
        std::list<int>::iterator it = easyfind(lst, 30);
        std::cout << "found value..." << *it << std::endl;
        
        std::cout << "searching 69 in list..." << std::endl;
        easyfind(lst, 69);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }
    
    return (0);
}