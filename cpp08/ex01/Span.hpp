#pragma once

#include <iostream>
#include <algorithm>
#include <vector>

class Span
{
    private:
        unsigned int N;
        std::vector<int> v;
    protected:

    public:
        Span();
        Span(unsigned int N);
        Span(const Span &copy);
        Span &operator=(const Span &copy);
        ~Span();
        void addNumber(int n);
        void addNumber();
        int shortestSpan();
        int longestSpan();
};