#ifndef SEARCHING_H
#define SEARCHING_H
#include <string>
using namespace std;
bool searchOperators(string equation, char operators, int &position)
{
    int parentesis = 0;
    while (position != 0)
    {
        position--;
        if (equation[position] == '(')
            parentesis++;
        if (equation[position] == ')')
            parentesis--;
        if (parentesis == 0 && equation[position] == operators)
            return true;
    }
    position = equation.length();
    return false;
}
#endif