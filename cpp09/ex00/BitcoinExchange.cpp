#include "BitcoinExchange.hpp"

bool BitcoinExchange::Errors(std::string input, int i)
{
    if (i == 0)
        std::cerr << "Error: could not open file." << std::endl;
    if (i == 1)
        std::cerr << "Error: not a positive number." << std::endl;
    if (i == 2)
        std::cerr << "Error: bad input => " << input << std::endl;
    if (i == 3)
        std::cerr << "Error: too large a number." << std::endl;
    if (i == 4)
        std::cerr << "Error" << std::endl;
    if (i == 5)
        std::cerr << "Error: bad date" << std::endl;
    return 0;
}

bool BitcoinExchange::InputCheck(std::string input)
{
    int flag = 0;
    if (input.length() < 13)
        return Errors(input, 2);
    for (unsigned long i = 0; i < input.length(); i++)
    {
        if (i == 4 || i == 7 || i == 10)
        {
            if (input.at(i) != '-' && input.substr(10, 3) != " | ")
                return Errors(input, 2);
        }
        else if (i < 10)
        {
            if (!isdigit(input.at(i)))
                return Errors(input, 2);
        }
        else
        {
            if (i == 11)
                i = 13;
            if (input.at(i) == '-')
                return Errors(input, 1);
            if (!isdigit(input.at(i)) && input.at(i) != '.')
                return Errors(input, 2);
            else if (input.at(i) == '.')
            {
                if (flag)
                    return Errors(input, 2);
                flag = 1;
            }
        }
    }
    try
    {
        std::stof(input.substr(13));
        int i = std::stoi(input.substr(13));
        if (i < 0 || i > 1000)
            return Errors("", 3);
        return isValidDate(input);
    }
    catch (const std::exception &e)
    {
        Errors("", 3);
    }
    return 0;
}

bool BitcoinExchange::isValidDate(std::string input)
{
    if (std::stoi(input.substr(0, 4)) < 2008)
        return Errors(input, 5);
    else if (std::stoi(input.substr(5, 2)) > 12)
        return Errors(input, 5);
    else if (std::stoi(input.substr(8, 2)) > 28)
    {
        for (size_t i = 2008; i < 2025; i += 4)
        {
            if (!strcmp((input.substr(0, 4)).c_str(), std::to_string(i).c_str()))
            {
                if (std::stoi(input.substr(8, 2)) == 29)
                    return 1;
            }
        }
    }
    if (std::stoi(input.substr(8, 2)) <= 28)
        return 1;
    else if (std::stoi(input.substr(5, 2)) == 2)
        return Errors(input, 5);
    else
    {
        if (MonthCalculator(std::stoi(input.substr(5, 2)), std::stoi(input.substr(0, 4))) < std::stoi(input.substr(8, 2)))
            return Errors(input, 5);
    }
    return 1;
}

int BitcoinExchange::MonthCalculator(int i, int j)
{
    if (i == 4 || i == 6 || i == 9 || i == 11)
        return 30;
    else if (i == 2)
    {
        if (j % 4 == 0)
            return 29;
        else
            return 28;
    }
    else
        return 31;
}

float BitcoinExchange::Calculator(std::string input, float s)
{
    std::map<int, Data>::iterator it;
    int day = std::stoi(input.substr(8, 2));
    int mon = std::stoi(input.substr(5, 2));
    int year = std::stoi(input.substr(0, 4));
    int tmp_day;
    int tmp_mon;
    int tmp_year;

    for (; year > 2008;)
    {
        it = this->data.begin();
        for (; it != this->data.end(); it++)
        {
            tmp_day = std::stoi(it->second.date.substr(8, 2));
            tmp_mon = std::stoi(it->second.date.substr(5, 2));
            tmp_year = std::stoi(it->second.date.substr(0, 4));
            if (day == tmp_day && mon == tmp_mon && tmp_year == year)
                return it->second.value * s;
        }
        if (day == 0)
        {
            if (mon != 0)
                mon--;
            else
            {
                year--;
                mon = 12;
            }
            day = MonthCalculator(mon, year);
        }
        day--;
    }
    return 0;
}

void BitcoinExchange::start(std::string str)
{
    std::string read;
    Data val;
    std::ifstream data("data.csv");
    std::ifstream input(str.c_str());
    if (!data.is_open() || !input.is_open())
        throw std::exception();
    getline(data, read);
    for (int i = 0; getline(data, read); i++)
    {
        val.date = read.substr(0, 10);
        val.value = std::stof(read.substr(11));
        this->data.insert(std::make_pair(i, val));
    }
    getline(input, read);
    if ((read == "date | value"))
    {
        for (; getline(input, read);)
        {
            if (InputCheck(read))
                std::cout << read.substr(0, 10) << " => " << std::stof(read.substr(13)) << " = " << Calculator(read, std::stof(read.substr(13))) << std::endl;
        }
    }
    else
        std::cerr << "Error: bad input\n";
    data.close();
    input.close();
}