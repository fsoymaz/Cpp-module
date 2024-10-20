#include "BitcoinExchange.hpp"
#include <fstream>
#include <sstream>
#include <stdexcept>

BitcoinExchange::BitcoinExchange(const std::string& dbFile) {
    loadDatabase(dbFile);
}

void BitcoinExchange::loadDatabase(const std::string& dbFile) {
    std::ifstream file(dbFile.c_str());
    if (!file.is_open()) {
        throw std::runtime_error("Error: could not open file " + dbFile);
    }

    std::string line;
    while (std::getline(file, line)) {
        std::istringstream ss(line);
        std::string date;
        double rate;
        if (std::getline(ss, date, ',') && ss >> rate) {
            exchangeRates[date] = rate;
        }
    }
    file.close();
}

double BitcoinExchange::getExchangeRate(const std::string& date) const {
    std::map<std::string, double>::const_iterator it = exchangeRates.lower_bound(date);
    if (it == exchangeRates.end() || it->first != date) {
        if (it == exchangeRates.begin()) {
            throw std::invalid_argument("Error: date not found.");
        }
        --it;
    }
    return it->second;
}
