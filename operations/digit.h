#ifndef DIGIT_H
#define DIGIT_H
#include <string>
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
#endif