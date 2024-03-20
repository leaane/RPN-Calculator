#ifndef CS3A_RPN_H
#define CS3A_RPN_H

#include <iostream>
#include <stack>
#include <cmath>

class RPN {
private:
    double evaluate(double left, char op, double right);

public:
    static double evaluate(const std::string& postfixExpression);

};


#endif //CS3A_RPN_H
