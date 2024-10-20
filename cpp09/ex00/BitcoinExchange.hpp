#pragma once

#include <iostream>
#include <map>
#include <string>

class BitcoinExchange {
public:
    BitcoinExchange(const std::string& dbFile);
    double getExchangeRate(const std::string& date) const;
    
private:
    void loadDatabase(const std::string& dbFile);
    std::map<std::string, double> exchangeRates;
};