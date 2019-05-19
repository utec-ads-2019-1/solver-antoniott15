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
    float operate();
};
float digit::operate()
{
    return data;
}

class adition : public Operation
{
public:
    adition(Operation *left_, Operation *right_) : Operation(left_, right_){};
    float operate();
};
float adition::operate()
{
    Operation::operate();
    return left->operate() + right->operate();
}

class substraction : public Operation
{
public:
    substraction(Operation *left_, Operation *right_) : Operation(left_, right_){};
    float operate();
};
float substraction::operate()
{
    Operation::operate();
    return left->operate() - right->operate();
}

class multiply : public Operation
{
public:
    multiply(Operation *left_, Operation *right_) : Operation(left_, right_){};
    float operate();
};
float multiply::operate()
{
    Operation::operate();
    return left->operate() * right->operate();
}

class division : public Operation
{
public:
    division(Operation *left_, Operation *right_) : Operation(left_, right_){};
    float operate();
};
float division::operate()
{
    Operation::operate();
    return left->operate() / right->operate();
}

class powNumber : public Operation
{
public:
    powNumber(Operation *left_, Operation *right_) : Operation(left_, right_){};
    float operate();
};
float powNumber::operate()
{
    Operation::operate();
    return pow(left->operate(), right->operate());
}
#endif