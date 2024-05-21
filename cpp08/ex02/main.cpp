#include "MutantStack.hpp"

int main()
{
    std::vector<std::vector<int> > v;
    v.push_back(std::vector<int>());
    v.push_back(std::vector<int>());

    std::cout << "Test 1" << std::endl;
    try
    {
        MutantStack<int> mstack;
        mstack.push(5);
        mstack.push(17);
        std::cout << mstack.top() << std::endl;
        v[0].push_back(mstack.top()); // +
        mstack.pop(); 
        std::cout << mstack.size() << std::endl;
        v[0].push_back(mstack.size()); // +
        mstack.push(3);
        mstack.push(5);
        mstack.push(737);
        //[...]
        mstack.push(03);
        MutantStack<int>::iterator it = mstack.begin();
        MutantStack<int>::iterator ite = mstack.end();
        ++it;
        --it;
        while (it != ite)
        {
            std::cout << *it << std::endl;
            v[0].push_back(*it); // +
            ++it;
        }
        std::stack<int> s(mstack);
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
    }

    std::cout << std::endl
              << "Test 2" << std::endl;
    try
    {
        std::list<int> mstack;
        mstack.push_back(5);
        mstack.push_back(17);
        std::cout << mstack.back() << std::endl;
        v[1].push_back(mstack.back());
        mstack.pop_back();
        std::cout << mstack.size() << std::endl;
        v[1].push_back(mstack.size());
        mstack.push_back(3);
        mstack.push_back(5);
        mstack.push_back(737);
        //[...]
        mstack.push_back(03);
        std::list<int>::iterator it = mstack.begin();
        std::list<int>::iterator ite = mstack.end();
        ++it;
        --it;
        while (it != ite)
        {
            std::cout << *it << std::endl;
            v[1].push_back(*it);
            ++it;
        }
        std::list<int> s(mstack);
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
    }
    
    std::cout << std::endl << "Final results" << std::endl;
    std::cout << "MutantStack - OtherContainer" << std::endl;
    for(unsigned long i = 0; i < v[0].size(); i++)
        std::cout << v[0][i] << " - " << v[1][i] << std::endl;
    return 0;
}