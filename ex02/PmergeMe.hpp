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
        void mergeDeque(int start, int end);
        void mergeVector(int start, int end);
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

template <typename V>
void insertion(V & container, int start, int end)
{
    int temp;
    int j;
    for (int i = start + 1; i <= end; i++)
    {
        temp = container[i];
        j = i - 1;
        while (j >= 0 && container[j] > temp)
        {
            container[j + 1] = container[j];
            j--;
        }
        container[j + 1] = temp;
    }
}