#pragma once

#include <iostream>
#include <algorithm>
#include <fstream>
#include <map>

struct Data
{
    std::string date;
    float value;
};

class BitcoinExchange
{
    private:
        std::map<int, Data> data;

    protected:

    public:
        void start(std::string str);
        bool InputCheck(std::string input);
        bool Errors(std::string input, int i);
        bool isValidDate(std::string input);
        float Calculator(std::string input, float s);
        int MonthCalculator(int i, int j);
};