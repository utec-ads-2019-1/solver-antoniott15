#include "operation.h"
#include <iostream>
#include <vector>
using namespace std;
void getParenthesis(string equation, char digits, int &position)
{
    int parenthesis = 0;
    while (position != 0)
    {
        position--;
        if (equation[position] == '(')
        {
            parenthesis++;
        }
        if (equation[position] == ')')
        {
            parenthesis--;
        }
    }
}

Operation *Operation::buildFromEquation(string equation)
{

    return 0;
}