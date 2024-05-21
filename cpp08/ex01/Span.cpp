#include "Span.hpp"

Span::Span()
{
    this->N = 0;
}

Span::Span(unsigned int N)
{
    this->N = N;
}

Span::Span(const Span &copy)
{
    *this = copy;
}

Span &Span::operator=(const Span &copy)
{
    this->N = copy.N;
    this->v = copy.v;
    return *this;
}

Span::~Span()
{
    
}

void Span::addNumber(int n)
{
    if (this->v.size() < this->N)
        this->v.push_back(n);
    else
        throw std::exception();
}

void Span::addNumber()
{
    std::srand(std::time(NULL));
    unsigned int index = this->v.size();
    if(index >= this->N)
        throw std::exception();
    while (index < this->N)
    {
        this->v.push_back(rand() % 10000);
        index++;
    }
}

int Span::shortestSpan()
{
    if (this->v.size() <= 1)
        throw std::exception();
    std::vector<int> tmp = this->v;
    std::sort(tmp.begin(), tmp.end());
    int min = tmp[1] - tmp[0];
    for (unsigned int i = 1; i < tmp.size(); i++)
    {
        if (tmp[i] - tmp[i - 1] < min)
            min = tmp[i] - tmp[i - 1];
    }
    return min;
}

int Span::longestSpan()
{
    if (this->v.size() <= 1)
        throw std::exception();
    std::vector<int> tmp = this->v;
    std::sort(tmp.begin(), tmp.end());
    return tmp[tmp.size() - 1] - tmp[0];
}

