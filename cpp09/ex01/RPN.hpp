#ifndef RPN_HPP
#define RPN_HPP

#include <string>
#include <stack>
#include <stdexcept>

class RPN {
public:
    RPN();
    ~RPN();
    int evaluate(const std::string &expression);

private:
    bool isOperator(char c);
    int performOperation(int a, int b, char op);
};

#endif
