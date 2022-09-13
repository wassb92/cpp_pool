/*
** EPITECH PROJECT, 2022
** src informations
** File description:
** OS
*/

#include <iostream>
#include "OS.hpp"

OS::OS()
{
    uname(&info);
}

OS::~OS()
{
}

std::string OS::getName() const
{
    return info.sysname;
}

std::string OS::getKernel() const
{
    return info.release;
}

void OS::drawModule(sf::RenderWindow &window, Text text)
{
    text.setInfoAndDisplay("OS Name:\n   " + getName(), 830, 170, 20, sf::Color::White, window);
    text.setInfoAndDisplay("Kernel Version:\n   " + getKernel(), 830, 240, 20, sf::Color::White, window);
}
