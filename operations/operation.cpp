#include "operation.h"
#include <iostream>
#include <string>
#include <vector>
using namespace std;

bool Digit(string equation)
{
    for (int i = 0; i < equation.length(); i++)
    {
        if (!(equation[i] >= '0' && equation[i] <= '9'))
            return false;
    }
    return true;
}

Operation *buildFromEquation(string equation)
{
    int position = equation.length() - 1;

    int newPositionPow = equation.find('^');
    int newPositionMult = equation.find('*');
    int newPositionDiv = equation.find('/');
    int newPositionSubs = equation.find('-');
    int newPositionPlus = equation.find('+');
    if (equation[newPositionPow] != -1)
    {
        cout << equation[newPositionPow] << endl;

        string rightExpression = equation.substr(0, position);
        string leftExpression = equation.substr(position);
        cout << rightExpression << endl;
        cout << leftExpression << endl;
        return new powNumber(buildFromEquation(rightExpression), buildFromEquation(leftExpression));
    }
    else if (Digit(equation))
    {
        float numbers = strtof(equation.c_str(), 0);
        return new factorEx(numbers);
    }
}

int main()
{
    string expression = "4^2";
    Operation *equation = buildFromEquation(expression);
    cout << equation->operate() << endl;
    return 0;
}