#include "BitcoinExchange.hpp"
#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include <string>
#include <cctype>

// Function to check if a year is a leap year
bool isLeapYear(int year) {
    return (year % 4 == 0);
}

// Function to validate the date format and the actual day of the month
bool isValidDate(const std::string& date) {
    if (date.size() != 10) return false;
    if (!isdigit(date[0]) || !isdigit(date[1]) || !isdigit(date[2]) || !isdigit(date[3])) return false;
    if (date[4] != '-') return false;
    if (!isdigit(date[5]) || !isdigit(date[6])) return false;
    if (date[7] != '-') return false;
    if (!isdigit(date[8]) || !isdigit(date[9])) return false;

    int year = std::atoi(date.substr(0, 4).c_str());
    int month = std::atoi(date.substr(5, 2).c_str());
    int day = std::atoi(date.substr(8, 2).c_str());

    if (month < 1 || month > 12) return false;

    static const int daysInMonth[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
    int maxDay = daysInMonth[month - 1];

    if (month == 2 && isLeapYear(year)) {
        maxDay = 29;
    }

    return day >= 1 && day <= maxDay;
}

bool isValidValue(const std::string& value) {
    std::istringstream ss(value);
    double val;
    ss >> val;
    return !ss.fail() && ss.eof() && val >= 0 && val <= 1000;
}

int main(int argc, char* argv[]) {
    if (argc != 2) {
        std::cerr << "Error: could not open file." << std::endl;
        return 1;
    }

    std::ifstream inputFile(argv[1]);
    if (!inputFile.is_open()) {
        std::cerr << "Error: could not open file." << std::endl;
        return 1;
    }

    try {
        BitcoinExchange btc("data.csv");
    } catch (const std::runtime_error& e) {
        std::cerr << e.what() << std::endl;
        return 1;
    }

    std::string line;
    while (std::getline(inputFile, line)) {
        std::istringstream ss(line);
        std::string date, value;

        if (std::getline(ss, date, '|') && std::getline(ss, value)) {
            date = date.substr(0, date.find_last_not_of(" \t\n\r\f\v") + 1);
            value = value.substr(value.find_first_not_of(" \t\n\r\f\v"));

            if (!isValidDate(date)) {
                std::cerr << "Error: bad input => " << date << std::endl;
                continue;
            }

            if (!isValidValue(value)) {
                std::cerr << "Error: not a positive number." << std::endl;
                continue;
            }

            double val;
            std::istringstream valueStream(value);
            valueStream >> val;
            if (val > 1000) {
                std::cerr << "Error: too large a number." << std::endl;
                continue;
            }

            try {
                BitcoinExchange btc("data.csv"); // Ensure btc object is available here
                double rate = btc.getExchangeRate(date);
                std::cout << date << " => " << value << " = " << val * rate << std::endl;
            } catch (const std::invalid_argument& e) {
                std::cerr << e.what() << std::endl;
            }
        }
    }

    inputFile.close();
    return 0;
}
