/*
** EPITECH PROJECT, 2022
** c++pool B-PDG-300-PAR-3-1-PDGD12-
** File description:
** Command
*/

#ifndef COMMAND_HPP
#define COMMAND_HPP

#include <iostream>
#include <map>
#include <functional>
#include <vector>

typedef std::function<void()> fctPtr;

class Command {
public:
    void registerCommand(const std::string &name, const std::function<void()> &function);
    void executeCommand(const std::string &name);
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
    std::map<std::string, fctPtr> commandMap;
    std::vector<std::map<std::string, fctPtr>> commandVec;
};

#endif /* !COMMAND_HPP */
