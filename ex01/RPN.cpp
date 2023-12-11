#include "RPN.hpp"

RPN::RPN(std::string expr)
{
    std::string valid = "0123456789+-/* ";
    std::size_t found = expr.find_first_not_of(valid);

    if (found == std::string::npos)
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
    int result;

    while (ss >> token)
    {
        if (token == "+" || token == "-" || token == "/" || token == "*")
        {
            if (this->_expr.size() == 2)
            {
                int n1 = this->_expr.pop();
                int n2 = this->_expr.pop();
                /*switch(token)
                {
                    case "+":
                    case "-":
                    case "/":
                    case "*":
                }*/
            }
            else
                throw (RPN::InvalidExpr());
            //mirar que haya dos numeros en el stack
            //sacar esos dos numeros del stack
            //hacer la operacion
            //insertar el resultado en el stack
        }
    }
}

const char* RPN::InvalidExpr::what() const throw
{
    return ("Invalid expresion");
}