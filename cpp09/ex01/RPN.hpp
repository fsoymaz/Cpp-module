#pragma once

#include <iostream>
#include <algorithm>
#include <fstream>
#include <vector>

class RPN
{
    private:
        std::vector<int> _vals;
        std::vector<int> _res;

    protected:

    public:
        void start(std::string);
        int Calculator(int, int, char);

};