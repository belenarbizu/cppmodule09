#include "RPN.hpp"

int main(int argc, char **argv)
{
    if (argc != 2)
    {
        std::cout << "Insert one argv" << std::endl;
    }
    else
    {
        try
        {
            RPN rpn(argv[1]);
        }
        catch (std::exception & e)
        {
            std::cout << e.what() << std::endl;
        }
    }
    return 0;
}