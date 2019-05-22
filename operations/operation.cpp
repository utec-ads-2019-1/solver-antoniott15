#include "operation.h"
#include <iostream>
#include <string>
#include <vector>
#include "searching.h"
#include "remove.h"
#include "digit.h"
using namespace std;

Operation *buildFromEquation(string equation)
{
    int position = equation.length() - 1;
    int positionsTotal[7] = {
        equation.find('^'),
        equation.find('*'),
        equation.find('/'),
        equation.find('-'),
        equation.find('+'),
        equation.find('('),
        equation.find(')')};

    if (positionsTotal[5] == -1 && positionsTotal[6] == -1)
    {
        if (positionsTotal[4] != -1)
        {
            if (searchOperators(equation, '+', position))
            {
                string rightExpression = equation.substr(0, position);
                string leftExpression = equation.substr(position + 1);
                return new adition(buildFromEquation(rightExpression), buildFromEquation(leftExpression));
            }
        }
        if (positionsTotal[3] != -1)
        {
            if (searchOperators(equation, '-', position))
            {
                string rightExpression = equation.substr(0, position);
                string leftExpression = equation.substr(position + 1);
                return new substraction(buildFromEquation(rightExpression), buildFromEquation(leftExpression));
            }
        }
        if (positionsTotal[1] != -1)
        {
            if (searchOperators(equation, '*', position))
            {
                string rightExpression = equation.substr(0, position);
                string leftExpression = equation.substr(position + 1);
                return new multiply(buildFromEquation(rightExpression), buildFromEquation(leftExpression));
            }
        }
        if (positionsTotal[2] != -1)
        {
            if (searchOperators(equation, '/', position))
            {
                string rightExpression = equation.substr(0, position);
                string leftExpression = equation.substr(position + 1);
                return new division(buildFromEquation(rightExpression), buildFromEquation(leftExpression));
            }
        }

        if (positionsTotal[0] != -1)
        {
            if (searchOperators(equation, '^', position))
            {
                string rightExpression = equation.substr(0, position);
                string leftExpression = equation.substr(position + 1);
                return new powNumber(buildFromEquation(rightExpression), buildFromEquation(leftExpression));
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
            return buildFromEquation(equation);
        }
    }
    else
    {
        if (searchOperators(equation, '+', position))
        {
            string rightExpression = equation.substr(0, position);
            string leftExpression = equation.substr(position + 1);
            return new adition(buildFromEquation(rightExpression), buildFromEquation(leftExpression));
        }

        if (searchOperators(equation, '-', position))
        {
            string rightExpression = equation.substr(0, position);
            string leftExpression = equation.substr(position + 1);
            return new substraction(buildFromEquation(rightExpression), buildFromEquation(leftExpression));
        }

        if (searchOperators(equation, '*', position))
        {
            string rightExpression = equation.substr(0, position);
            string leftExpression = equation.substr(position + 1);
            return new multiply(buildFromEquation(rightExpression), buildFromEquation(leftExpression));
        }

        if (searchOperators(equation, '/', position))
        {
            string rightExpression = equation.substr(0, position);
            string leftExpression = equation.substr(position + 1);
            return new division(buildFromEquation(rightExpression), buildFromEquation(leftExpression));
        }

        if (searchOperators(equation, '^', position))
        {
            string rightExpression = equation.substr(0, position);
            string leftExpression = equation.substr(position + 1);
            return new powNumber(buildFromEquation(rightExpression), buildFromEquation(leftExpression));
        }

        if (Digit(equation))
        {
            float numbers = strtof(equation.c_str(), 0);
            return new factorEx(numbers);
        }
        else
        {
            equation = remove(equation);
            return buildFromEquation(equation);
        }
    }
}

int main()
{
    string expression = "8*(-2)";
    Operation *equation = buildFromEquation(expression);
    cout << equation->operate() << endl;
    return 0;
}