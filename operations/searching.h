#ifndef SEARCHING_H
#define SEARCHING_H
#include <string>
using namespace std;
bool searchOperators(string equation, char operators, int &position)
{
    int parentesis = 0, count1 = 0, count2 = 0;
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
    if (count1 == count2)
    {
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
    }
    else
    {
        cout << "Parentesis desbalanceados no se puede seguir con la operacion." << endl;
        throw;
    }
    position = equation.length();
    return false;
}
#endif