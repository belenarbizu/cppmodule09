#pragma once

#include <iostream>
#include <stack>
#include <sstream>
#include <string>
#include <exception>

class RPN
{
    private:
        std::stack<int> _expr;
    public:
        RPN(std::string expr);
        ~RPN();
        RPN(const RPN & rpn);
        RPN& operator=(const RPN & rpn);

        void execute_expr(std::string expr);

        class InvalidExpr : public std::exception
        {
            public:
                const char* what() const throw();
        };
        class DivideByZero : public std::exception
        {
            public:
                const char* what() const throw();
        };
};