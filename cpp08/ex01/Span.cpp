#include "Span.hpp"

Span::Span() : _maxSize(0) {}

Span::Span(unsigned int n) : _maxSize(n) {}

Span::Span(Span const & src) : _maxSize(src._maxSize), _vec(src._vec) {}

Span::~Span() {}

Span & Span::operator=(Span const & rhs)
{
    if (this != &rhs)
    {
        this->_maxSize = rhs._maxSize;
        this->_vec = rhs._vec;
    }
    return (*this);
}

void Span::addNumber(int number)
{
    if (_vec.size() >= _maxSize)
        throw SpanFullException();
    _vec.push_back(number);
}

int Span::shortestSpan() const
{
    if (_vec.size() < 2)
        throw NotEnoughElementsException();
    
    // copy to not change the original value and sort to find the shortest diff
    std::vector<int> temp = _vec;
    std::sort(temp.begin(), temp.end());

    int minSpan = temp[1] - temp[0];
    for (size_t i = 1; i < temp.size() - 1; i++)
    {
        int diff = temp[i + 1] - temp[i];
        if (diff < minSpan)
            minSpan = diff;
    }
    return (minSpan);
}
 
int Span::longestSpan() const
{
    if (_vec.size() < 2)
        throw NotEnoughElementsException();
    
    int min = *std::min_element(_vec.begin(), _vec.end());
    int max = *std::max_element(_vec.begin(), _vec.end());

    return (max - min);
}

const char* Span::SpanFullException::what() const throw() {
    return "Error: SPan Max capacity reached.";
}

const char* Span::NotEnoughElementsException::what() const throw() {
    return "Error: Not Enough Elements to find a Span. (min 2)";
}