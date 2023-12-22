#pragma once

#include <iostream>
#include <vector>
#include <deque>
#include <stdlib.h>
#include <sstream>
#include <ctime>

class PmergeMe
{
    private:
        std::deque<int> _deque;
        std::vector<int> _vector;
        PmergeMe(const PmergeMe & pm);
        PmergeMe& operator=(const PmergeMe & pm);
        void mergeDeque();
        void mergeVector();
    public:
        PmergeMe(int argc, char **argv);
        ~PmergeMe();

    class WrongInput : public std::exception
    {
        public:
            const char* what() const throw();
    };
};

template <typename T>
void display(T & container)
{
    typename T::iterator it;
    for (it = container.begin(); it != container.end(); it++)
    {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
}