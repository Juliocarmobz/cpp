#ifndef SPAN_HPP
# define SPAN_HPP

# include <vector>
# include <algorithm>
# include <exception>
# include <iterator>
# include <iostream>

class Span
{
    private:
        unsigned int        _maxSize;
        std::vector<int>    _vec;
    
        // private constructor to block contruction withnout N size
        Span();
    public:
        Span(unsigned int n);
        Span(Span const & src);
        ~Span();
        Span & operator=(Span const & rhs);

        void addNumber(int number);
        int shortestSpan() const;
        int longestSpan() const;

        template <typename Iterator>
        void addNumbers(Iterator begin, Iterator end)
        {
            unsigned int distance = std::distance(begin, end);
            if (_vec.size() + distance > _maxSize)
                throw SpanFullException();
            _vec.insert(_vec.end(), begin, end);
        }

        class SpanFullException : public std::exception
        {
            public:
                virtual const char *what() const throw();
        };
        
        class NotEnoughElementsException : public std::exception
        {
            public:
                virtual const char *what() const throw();
        };
};

#endif