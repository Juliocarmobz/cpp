#ifndef EASYFIND_TPP
# define EASYFIND_TPP

# include "easyfind.hpp"

template <typename T>
typename T::iterator easyfind(T &container, int value)
{
    // std::find search end to end the value
    typename T::iterator it = std::find(container.begin(), container.end(), value);

    // if iterator return the end of the container, means that does not find the value
    if (it == container.end())
        throw NotFoundException();

    return (it);
}

#endif