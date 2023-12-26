#include "PmergeMe.hpp"

PmergeMe::PmergeMe(int argc, char **argv)
{
    clock_t init;
    clock_t finish;
    double time_dq;
    double time_vt;

    for (int i = 1; i < argc; i++)
    {
        std::istringstream ss(argv[i]);
        int result;

        if (!(ss >> result) || result < 0)
            throw (PmergeMe::WrongInput());
        this->_deque.push_back(result);
        this->_vector.push_back(result);
    }
    std::cout << "Before: ";
    display(this->_deque);

    init = clock();
    mergeDeque(0, this->_deque.size() - 1);
    finish = clock();
    time_dq = (double)(finish - init) / CLOCKS_PER_SEC;

    init = clock();
    mergeVector(0, this->_vector.size() - 1);
    finish = clock();
    time_vt = (double)(finish - init) / CLOCKS_PER_SEC;
    std::cout << "After: ";
    display(this->_vector);

    std::cout << "Time to process a range of " << argc - 1 << " elements with std::deque : " << std::fixed << time_dq << " us" << std::endl;
    std::cout << "Time to process a range of " << argc - 1 << " elements with std::vector : " << std::fixed << time_vt << " us" << std::endl;
}


void PmergeMe::mergeDeque(int start, int end)
{
    int mid;

    mid = (start + end) / 2;
    if (start < end)
    {
        mergeDeque(start, mid);
        mergeDeque(mid + 1, end);
        insertion(this->_deque, start, end);
    }
}

void PmergeMe::mergeVector(int start, int end)
{
    int mid;

    mid = (start + end) / 2;
    if (start < end)
    {
        mergeVector(start, mid);
        mergeVector(mid + 1, end);
        insertion(this->_vector, start, end);
    }
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