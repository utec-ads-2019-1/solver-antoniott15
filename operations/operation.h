#ifndef OPERATION_H
#define OPERATION_H

#include <string>
#include <math.h>
using namespace std;

class Operation
{
protected:
    string equation;

public:
    Operation *left;
    Operation *right;
    int data;
    Operation() : left(nullptr), right(nullptr){};
    Operation(Operation *left, Operation *right) : left(left), right(right){};
    Operation(int result) : data(result){};
    static Operation *buildFromEquation(string equation);
    virtual float operate() = 0;
};

class digit : public Operation
{
public:
    digit(int number) : Operation(number) {}
    float operate()
    {
        return data;
    }
};
class add : public Operation
{
public:
    add(Operation *left_, Operation *right_) : Operation(left_, right_){};
    float operate()
    {
        return left->operate() + right->operate();
    }
};
class subs : public Operation
{
public:
    subs(Operation *left_, Operation *right_) : Operation(left_, right_){};
    float operate()
    {
        return left->operate() - right->operate();
    }
};

class multiply : public Operation
{
public:
    multiply(Operation *left_, Operation *right_) : Operation(left_, right_){};
    float operate()
    {
        return left->operate() * right->operate();
    }
};

class division : public Operation
{
public:
    division(Operation *left_, Operation *right_) : Operation(left_, right_){};
    float operate()
    {
        return left->operate() / right->operate();
    }
};

class powEquation : public Operation
{
public:
    powEquation(Operation *left_, Operation *right_) : Operation(left_, right_){};
    float operate()
    {
        return pow(left->operate(), right->operate());
    }
};
#endif