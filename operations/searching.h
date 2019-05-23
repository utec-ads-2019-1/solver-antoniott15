#ifndef SEARCHING_H
#define SEARCHING_H
#include <string>
using namespace std;

void balanced(string equation)
{
    int count1 = 0, count2 = 0;
    for (int i = 0; i <= equation.length(); i++)
    {
        if (equation[i] == '(')
        {
            count1++;
        }
        if (equation[i] == ')')
        {
            count2++;
        }
    }
    if (count1 != count2)
    {
        cout << "Parentesis desbalanceados no se puede seguir con la operacion." << endl;
        throw;
    }
}
bool searchOperators(string equation, char operators, int &position)
{
    int parentesis = 0;
    balanced(equation);
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