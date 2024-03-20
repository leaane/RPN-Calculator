#include "RPN.h"

double RPN::evaluate(double left, char op, double right) {
    switch (op) {
        case '+': return left + right;
        case '-': return left - right;
        case '^': return std::pow(left, right);
        case '/': return left / right;
        case '*': return left * right;
        default: return 0;
    }
}


double RPN::evaluate(const std::string& postfixExpression) {
    std::stack<double> stack;

    for (int i = 0; i < postfixExpression.length(); i++) {
        char c = postfixExpression[i];

        if (isdigit(c)) {
            stack.push(static_cast<double>(c - '0'));
        } else {
            double right, left;
            if(!stack.empty()) {
                right = stack.top();
                stack.pop();
            }

            if(!stack.empty()) {
                left = stack.top();
                stack.pop();
            }

            stack.push(RPN().evaluate(left, c, right));
        }
    }

    return stack.top();
}


