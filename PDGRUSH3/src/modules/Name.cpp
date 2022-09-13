/*
** EPITECH PROJECT, 2022
** B-PDG-300-PAR-3-1-PDGRUSH3-
** File description:
** Name
*/

#include "Name.hpp"
#include "const.hpp"

std::string Name::getHostName() const
{
    char hostName[100];

    gethostname(hostName, 100);
    if (!hostName)
        return EMPTY_STR;
    else
        return (hostName);
}

std::string Name::getUserName() const
{
    char userName[100];

    if (getlogin_r(userName, 100) != 0)
        return EMPTY_STR;
    else
        return (userName);
}

void Name::drawModule(sf::RenderWindow &window, Text text)
{
    text.setInfoAndDisplay("Host Name:\n   " + getHostName(), 480, 170, 20, sf::Color::White, window);
    text.setInfoAndDisplay("User Name:\n   " + getUserName(), 480, 240, 20, sf::Color::White, window);
}