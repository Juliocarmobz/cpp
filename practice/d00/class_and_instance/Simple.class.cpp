#include <iostream>
#include "Simple.class.hpp"

Simple::Simple(void){

    std::cout << "Constructor called" << std::endl;
    return ;
}

Simple::~Simple(void){

    std::cout << "Destructor called" <<std::endl;
    return ;
}