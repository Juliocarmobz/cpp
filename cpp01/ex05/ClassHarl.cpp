#include "ClassHarl.hpp"

void    Harl::debug(void)
{
    std::cout << "DEGUB LEVEL: I love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. I really do!" << std::endl;
    return ;
}

void    Harl::info(void)
{
    std::cout << "INFO LEVEL: I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!" << std::endl;
    return ;
}

void    Harl::warning(void)
{
    std::cout << "WARNING LEVEL: I think I deserve to have some extra bacon for free. I’ve been coming for years, whereas you started working here just last month." << std::endl;
    return ;
}

void    Harl::error(void)
{
    std::cout << "ERROR LEVEL: This is unacceptable! I want to speak to the manager now." << std::endl;
    return ;
}

void    Harl::complain( std::string level )
{
    
}