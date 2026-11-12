#ifndef ITER_HPP
# define ITER_HPP
# include <cstddef>

template <typename T>
void iter(T *array, std::size_t const lenght, void (*func)(T &))
{
    for (std::size_t i = 0; i < lenght; i++)
        func(array[i]);
}

template <typename T>
void iter(T const *array, std::size_t const lenght, void (*func)(T const &))
{
    for (std::size_t i = 0; i < lenght; i++)
        func(array[i]);
}

#endif