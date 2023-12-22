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
    mergeDeque(); //ordena deque
    finish = clock();
    time_dq = (double)(finish - init) / CLOCKS_PER_SEC;

    init = clock();
    mergeVector(); //ordena vector
    finish = clock();
    time_vt = (double)(finish - init) / CLOCKS_PER_SEC;
    std::cout << "After: ";
    display(this->_deque);
    //display secuencia ordenada

    std::cout << "Time to process a range of " << argc - 1 << " elements with std::deque : " << time_dq << std::endl;
    std::cout << "Time to process a range of " << argc - 1 << " elements with std::list : " << time_vt << std::endl;
}

void PmergeMe::mergeDeque()
{
}

void PmergeMe::mergeVector()
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