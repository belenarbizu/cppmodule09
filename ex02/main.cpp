#include "PmergeMe.hpp"

int main(int argc, char **argv)
{
    if (argc > 1)
    {
        try
        {
            PmergeMe merge(argc, argv);
        }
        catch (std::exception & e)
        {
            std::cout << e.what() << std::endl;
        }
    }
    else
        std::cout << "Add a sequence of integers" << std::endl;
    return 0;
}