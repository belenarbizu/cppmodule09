#include "RPN.hpp"

RPN::RPN(std::string expr)
{
    std::string valid = "0123456789+-/* ";
    std::size_t found = expr.find_first_not_of(valid);

    if (found != std::string::npos)
        throw (RPN::InvalidExpr());
    else
        execute_expr(expr);
}
RPN::~RPN()
{
}
RPN::RPN(const RPN & rpn)
{
    *this = rpn;
}
RPN& RPN::operator=(const RPN & rpn)
{
    this->_expr = rpn._expr;
    return *this;
}

void RPN::execute_expr(std::string expr)
{
    std::istringstream ss(expr);
    std::string token;
    double result;

    while (ss >> token)
    {
        if (token.compare("+") == 0 || token.compare("-") == 0 || token.compare("/") == 0 || token.compare("*") == 0)
        {
            if (this->_expr.size() >= 2)
            {
                int n1 = this->_expr.top();
                this->_expr.pop();
                int n2 = this->_expr.top();
                this->_expr.pop();
                if (token.compare("+") == 0)
                {
                    result = n1 + n2;
                    this->_expr.push(result);
                }
                else if (token.compare("-") == 0)
                {
                    result = n2 - n1;
                    this->_expr.push(result);
                }
                else if (token.compare("/") == 0)
                {
                    if (n2 == 0)
                        throw (RPN::DivideByZero());
                    result = n1 / n2;
                    this->_expr.push(result);
                }
                else
                {
                    result = n1 * n2;
                    this->_expr.push(result);
                }
            }
            else
                throw (RPN::InvalidExpr());
        }
        else
            this->_expr.push(std::stoi(token));
    }
    if (this->_expr.size() == 1)
        std::cout << this->_expr.top() << std::endl;
    else
        throw (RPN::InvalidExpr());
}

const char* RPN::InvalidExpr::what() const throw()
{
    return ("Invalid expresion");
}

const char* RPN::DivideByZero::what() const throw()
{
    return ("Can't divide by 0");
}