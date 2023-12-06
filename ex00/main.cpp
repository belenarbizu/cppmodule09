#include "BitcoinExchange.hpp"

int main(int argc, char **argv)
{
    if (argc != 2)
    {
        std::cout << "Error: ./btc file" << std::endl;
        return 1;
    }
    
    BitcoinExchange bit(argv[1]);
    return 0;
}