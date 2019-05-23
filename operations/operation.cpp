#include "operation.h"
#include <iostream>
#include <string>
#include <vector>
#include "searching.h"
#include "remove.h"
#include "digit.h"

using namespace std;

Operation *getOperation(char operators, string left, string right)
{
    if (operators == '+')
    {
        return new adition(Operation::buildFromEquation(right), Operation::buildFromEquation(left));
    }
    else if (operators == '-')
    {
        return new substraction(Operation::buildFromEquation(right), Operation::buildFromEquation(left));
    }
    else if (operators == '*')
    {
        return new multiply(Operation::buildFromEquation(right), Operation::buildFromEquation(left));
    }
    else if (operators == '/')
    {
        return new division(Operation::buildFromEquation(right), Operation::buildFromEquation(left));
    }
    else if (operators == '^')
    {
        return new powNumber(Operation::buildFromEquation(right), Operation::buildFromEquation(left));
    }
    return 0;
}

Operation *Operation::buildFromEquation(string equation)
{
    char operatorss[5] = {'+', '-', '*', '/', '^'};

    int position = equation.length() - 1;
    int positionsTotal[7] = {
        equation.find('+'),
        equation.find('-'),
        equation.find('*'),
        equation.find('/'),
        equation.find('^'),
        equation.find('('),
        equation.find(')')};

    if (positionsTotal[5] == -1 && positionsTotal[6] == -1)
    {
        for (int i = 0; i < 5; i++)
        {
            if (positionsTotal[i] != -1)
            {
                if (searchOperators(equation, operatorss[i], position))
                {
                    string rightExpression = equation.substr(0, position);
                    string leftExpression = equation.substr(position + 1);
                    return getOperation(operatorss[i], leftExpression, rightExpression);
                }
            }
        }
        if (Digit(equation))
        {
            float numbers = strtof(equation.c_str(), 0);
            return new factorEx(numbers);
        }
        else
        {
            equation = remove(equation);
            return Operation::buildFromEquation(equation);
        }
    }
    else
    {
        for (int i = 0; i < 5; i++)
        {
            if (searchOperators(equation, operatorss[i], position))
            {
                string rightExpression = equation.substr(0, position);
                string leftExpression = equation.substr(position + 1);
                return getOperation(operatorss[i], leftExpression, rightExpression);
            }
        }

        if (Digit(equation))
        {
            float numbers = strtof(equation.c_str(), 0);
            return new factorEx(numbers);
        }
        else
        {
            equation = remove(equation);
            return Operation::buildFromEquation(equation);
        }
    }
    return 0;
}

int main()
{
    string expression = "2++)+)+(++(+*3)";

    cout << expression << endl;
    Operation *equation = Operation::buildFromEquation(expression);
    cout << equation->operate() << endl;
    return 0;
}