/*
** EPITECH PROJECT, 2022
** c++pool B-PDG-300-PAR-3-1-PDGD12-
** File description:
** Stack
*/

#include "Stack.hpp"

void Stack::push(double value)
{
    stack.push(value);
}

double Stack::pop()
{
    if (stack.empty())
        throw Stack::Error("Empty stack");

    double tmpVal = stack.top();

    stack.pop();
    return tmpVal;
}

double Stack::top() const
{
    if (stack.empty())
        throw Stack::Error("Empty stack");
    return stack.top();
}

void Stack::add()
{
    if (stack.size() < 2)
        throw Stack::Error("Not enough operands");
    double tmpTopOne = stack.top();
    stack.pop();
    double tmpTopTwo = stack.top();
    stack.pop();
    stack.push(tmpTopOne + tmpTopTwo);
}

void Stack::sub()
{
    if (stack.size() < 2)
        throw Stack::Error("Not enough operands");
    double tmpTopOne = stack.top();
    stack.pop();
    double tmpTopTwo = stack.top();
    stack.pop();
    stack.push(tmpTopOne - tmpTopTwo);
}

void Stack::mul()
{
    if (stack.size() < 2)
        throw Stack::Error("Not enough operands");
    double tmpTopOne = stack.top();
    stack.pop();
    double tmpTopTwo = stack.top();
    stack.pop();
    stack.push(tmpTopOne * tmpTopTwo);
}

void Stack::div()
{
    if (stack.size() < 2)
        throw Stack::Error("Not enough operands");
    double tmpTopOne = stack.top();
    stack.pop();
    if (stack.top() == 0) {
        stack.push(tmpTopOne);
        return;
    }
    double tmpTopTwo = stack.top();
    stack.pop();
    stack.push(tmpTopOne / tmpTopTwo);
}
