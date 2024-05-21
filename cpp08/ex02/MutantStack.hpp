#pragma once
#include <stack>
#include <list>
#include <vector>
#include <iostream>

template <typename T>
class MutantStack : public std::stack<T>
{
    private:

    protected:

    public:
        MutantStack(void);
        MutantStack(MutantStack const &src);
        MutantStack &operator=(MutantStack const &src);
        ~MutantStack();
        typedef typename std::stack<T>::container_type::iterator iterator;
        iterator begin(void)
        {
            return this->c.begin();
        }
        iterator end(void)
        {
            return this->c.end();
        }
};

template <typename T>
MutantStack<T>::MutantStack() : std::stack<T>()
{

}

template <typename T>
MutantStack<T>::MutantStack(MutantStack<T> const &src) : std::stack<T>(src)
{
    *this = src;
};

template <typename T>
MutantStack<T> &MutantStack<T>::operator=(MutantStack<T> const &src)
{
    std::stack<T>::operator=(src);
    return *this;
}

template <typename T>
MutantStack<T>::~MutantStack()
{
    // std::cout << "Default destructor called" << std::endl;
}