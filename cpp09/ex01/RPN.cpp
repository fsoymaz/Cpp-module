#include "RPN.hpp"

int RPN::Calculator(int s1, int s2, char op)
{
    if (op == '+')
        return (s1 + s2);
    else if (op == '-')
        return (s1 - s2);
    else if (op == '*')
        return (s1 * s2);
    return (s1 / s2);
}

void RPN::start(std::string input)
{
    unsigned long i = 0;
    int tmp;
    int op = 0;
    int num = 0;
    for (; i < input.length(); i++)
    {
        if ((input.at(i) == '+' || input.at(i) == '-' || input.at(i) == '*' || input.at(i) == '/') && _res.size() == 0)
        {
            op++;
            if (_vals.size() < 2)
                throw std::exception();
            else if (input.at(i) == '+')
                tmp = Calculator(_vals.at(_vals.size() - 2), _vals.at(_vals.size() - 1), '+');
            else if (input.at(i) == '-')
                tmp = Calculator(_vals.at(_vals.size() - 2), _vals.at(_vals.size() - 1), '-');
            else if (input.at(i) == '*')
                tmp = Calculator(_vals.at(_vals.size() - 2), _vals.at(_vals.size() - 1), '*');
            else
                tmp = Calculator(_vals.at(_vals.size() - 2), _vals.at(_vals.size() - 1), '/');
            _vals.erase(_vals.end() - 1);
            _vals.erase(_vals.end() - 1);
            _res.push_back(tmp);
        }
        else if ((input.at(i) == '+' || input.at(i) == '-' || input.at(i) == '*' || input.at(i) == '/') && _res.size() != 0)
        {
            op++;
            if (input.at(i) == '+')
                tmp = Calculator(_res.at(0), _vals.at(_vals.size() - 1), '+');
            else if (input.at(i) == '-')
                tmp = Calculator(_res.at(0), _vals.at(_vals.size() - 1), '-');
            else if (input.at(i) == '*')
                tmp = Calculator(_res.at(0), _vals.at(_vals.size() - 1), '*');
            else
                tmp = Calculator(_res.at(0),_vals.at(_vals.size() - 1), '/');
            _vals.erase(_vals.end() - 1);
            _res.erase(_res.begin());
            _res.push_back(tmp);
        }
        else if (input.at(i) == ' ') {}
        else if (!isdigit(std::stoi(input.substr(i, 1))) || input.at(i) == '0')
        {
            _vals.push_back(std::stoi(input.substr(i, 1)));
            num++;
        }
        else
            throw std::exception();
    }
    if (num - 1 == op)
        std::cout << _res.at(0) << std::endl;
    else
        throw std::exception();
}