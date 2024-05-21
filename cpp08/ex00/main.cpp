#include "easyfind.hpp"

int main()
{
    std::cout << "Test 1" << std::endl;
    try
    {
        std::vector<int> v;
        v.push_back(1);
        v.push_back(2);
        v.push_back(3);
        std::cout << *(easyfind(v, 2)) << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
    }

    std::cout << "Test 2" << std::endl;
    try
    {
        std::vector<int> v;
        v.push_back(1);
        v.push_back(2);
        v.push_back(3);
        std::cout << *(easyfind(v, 5)) << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
    }

    std::cout << "Test 3" << std::endl;
    try
    {
        std::deque<int> d;
        d.push_back(1);
        d.push_back(2);
        d.push_back(3);
        std::cout << *(easyfind(d, 2)) << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
    }

    std::cout << "Test 4" << std::endl;
    try
    {
        std::list<int> l;
        l.push_back(1);
        l.push_back(2);
        l.push_back(3);
        std::cout << *(easyfind(l, 2)) << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
    }
}