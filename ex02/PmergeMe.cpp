#include "PmergeMe.hpp"

PmergeMe::PmergeMe(int argc, char **argv)
{
    for (int i = 1; i < argc; i++)
    {
        std::istringstream ss(argv[i]);
        int result;

        if (!(ss >> result) || result < 0)
            throw (PmergeMe::WrongInput());
        this->_deque.push_back(result);
        this->_list.push_back(result);
    }
    std::cout << "Before: ";
    display(this->_deque);

    //ordena deque
    //ordena list
    std::cout << "After: ";
    //display secuencia ordenada

    //añadir el tiempo
    std::cout << "Time to process a range of " << argc - 1 << " elements with std::deque : " << std::endl;
    std::cout << "Time to process a range of " << argc - 1 << " elements with std::list : " << std::endl;
}

void PmergeMe::mergeDeque()
{
}

void PmergeMe::mergeList()
{
}

PmergeMe::~PmergeMe()
{

}

PmergeMe::PmergeMe(const PmergeMe & pm)
{
    (void)pm;
}

PmergeMe& PmergeMe::operator=(const PmergeMe & pm)
{
    (void)pm;
    return *this;
}

const char* PmergeMe::WrongInput::what() const throw()
{
    return ("Wrong input, only positive integers.");
}