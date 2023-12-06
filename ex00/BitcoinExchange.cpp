#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange(std::string file)
{
    this->_in.open(file);
    if (!this->_in)
        throw (BitcoinExchange::NoFile());
    this->_db.open("data.csv");
    if (!this->_db)
        throw (BitcoinExchange::NoFile());
    fillDatabase();
}
BitcoinExchange::~BitcoinExchange()
{
}
BitcoinExchange::BitcoinExchange(const BitcoinExchange & be)
{
    *this = be;
}
BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange & be)
{
    (void)be;
    return *this;
}

void BitcoinExchange::fillDatabase()
{
    std::string line;
    std::size_t it;

    std::getline(this->_db, line);
    while (std::getline(this->_db, line))
    {
        it = line.find(',');
        if (it == std::string::npos)
            throw (BitcoinExchange::InvalidFormat());

        std::string date = line.substr(0, it);
        std::string value = line.substr(it + 1);
        
        std::istringstream conv(value);
        double result;

        if (!(conv >> result))
            throw (BitcoinExchange::InvalidFormat());

        this->_database[date] = result;
    }
    checkInput();
}

int BitcoinExchange::checkDate(std::string date)
{
    if (date.size() != 10)
    {
        std::cout << "Error: invalid date." << std::endl;
        return 0;
    }
    int year = std::stoi(date.substr(0, 4));
    if (year < 2009 || year > 9999 || date[4] != '-')
    {
        std::cout << "Error: invalid date." << std::endl;
        return 0;
    }
    int month = std::stoi(date.substr(5, 7));
    if (month < 1 || month > 12 || date[7] != '-')
    {
        std::cout << "Error: invalid date." << std::endl;
        return 0;
    }
    int day = std::stoi(date.substr(8, 10));
    if (day < 1 || day > 31)
    {
        std::cout << "Error: invalid date." << std::endl;
        return 0;
    }
    else if (month == 4 || month == 6 || month == 9 || month == 11)
    {
        if (day > 30)
        {
            std::cout << "Error: invalid date." << std::endl;
            return 0;
        }
    }
    else if (month == 2)
    {
        if (year % 4 == 0 && ((year % 100 != 0) ||(year % 100 == 0 && year % 400 == 0)))
        {
            if (day > 29)
            {
                std::cout << "Error: invalid date." << std::endl;
                return 0;
            }
        }
        else
        {
            if (day > 28)
            {
                std::cout << "Error: invalid date." << std::endl;
                return 0;
            }
        }
    }
    return 1;
}

int BitcoinExchange::checkValue(std::string value)
{
    int num;

    try
    {
        num = std::stoi(value);
    }
    catch (std::invalid_argument const& ex)
    {
        std::cout << "Error: invalid argument." << std::endl;
        return 0;
    }
    catch (std::out_of_range const& ex)
    {
        std::cout << "Error: too large a number." << std::endl;
        return 0;
    }
    if (num < 0)
    {
        std::cout << "Error: not a positive number." << std::endl;
        return 0;
    }
    return 1;
}

void BitcoinExchange::checkInput()
{
    std::string line;
    std::size_t it;

    std::getline(this->_in, line);
    while (std::getline(this->_in, line))
    {
        it = line.find('|');
        if (it == std::string::npos)
            std::cout << "Error: bad input => " << line << std::endl;
        else
        {
            std::string date = line.substr(0, it - 1);
            std::string value = line.substr(it + 2);

            if (checkDate(date))
            {
                if (checkValue(value))
                {
                    std::map<std::string, double>::iterator i = this->_database.lower_bound(date);
                    if (i->first != date)
                        --i;
                    double result = std::stod(value) * i->second;
                    std::cout << date << " => " << value << " = "  << result << std::endl;
                }
            }
        }
    }
}

const char* BitcoinExchange::NoFile::what() const throw()
{
    return ("Error: could not open file.");
}

const char* BitcoinExchange::InvalidFormat::what() const throw()
{
    return ("Error: invalid format.");
}