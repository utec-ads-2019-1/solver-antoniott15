#ifndef REMOVE_H
#define REMOVE_H
#include <string>
using namespace std;

string remove(string equation)
{
    if (equation[0] == '(' && equation[equation.length() - 1] == ')')
        return equation.substr(1, equation.length() - 2);
    return "";
}
#endif