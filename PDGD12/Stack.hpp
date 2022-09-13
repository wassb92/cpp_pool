/*
** EPITECH PROJECT, 2022
** c++pool B-PDG-300-PAR-3-1-PDGD12-
** File description:
** Stack
*/

#ifndef STACK_HPP
#define STACK_HPP

#include <iostream>
#include <stack>

class Stack {
public:
    std::stack<double> stack;
    void push(double value);
    double pop();
    double top() const;
    void add();
    void sub();
    void mul();
    void div();

    class Error : public std::exception {
    public:
        Error(const std::string &value)
            : error(value) {};
        std::string error;
        const char *what() const throw()
        {
            return error.c_str();
        }
    };

protected:
private:
};

#endif /* !STACK_HPP */
