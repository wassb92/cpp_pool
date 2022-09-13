/*
** EPITECH PROJECT, 2022
** c++pool B-PDG-300-PAR-3-1-PDGD12-
** File description:
** Command
*/

#include <iterator>
#include "Command.hpp"

void Command::registerCommand(const std::string &name, const std::function<void()> &function)
{
    for (auto it = commandMap.begin(); it != commandMap.end(); ++it)
        if (it->first == name)
            throw Command::Error("Already registered command");
    commandMap.insert(std::pair<std::string, fctPtr>(name, function));
}

void Command::executeCommand(const std::string &name)
{
    for (auto it = commandMap.begin(); it != commandMap.end(); ++it)
        if (it->first == name) {
            it->second();
            return;
        }
    throw Command::Error("Unknow command");
}
