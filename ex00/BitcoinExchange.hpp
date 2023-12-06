#pragma once

#include <fstream>
#include <iostream>
#include <exception>
#include <map>
#include <string>
#include <sstream>

class BitcoinExchange
{
    private:
        std::map<std::string, double> _database;
        std::ifstream _in;
        std::ifstream _db;
    public:
        BitcoinExchange(std::string file);
        ~BitcoinExchange();
        BitcoinExchange(const BitcoinExchange & be);
        BitcoinExchange& operator=(const BitcoinExchange & be);

        void fillDatabase();
        void checkInput();
        int checkDate(std::string date);
        int checkValue(std::string value);

        class NoFile : public std::exception
        {
            public:
                const char* what() const throw();
        };

        class InvalidFormat : public std::exception
        {
            public:
                const char* what() const throw();
        };
};