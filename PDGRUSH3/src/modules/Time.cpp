/*
** EPITECH PROJECT, 2022
** B-PDG-300-PAR-3-1-PDGRUSH3-
** File description:
** Time
*/

#include "Time.hpp"

std::string Time::getTime() const
{
    time_t currentTime = time(0);
    std::string dt = ctime(&currentTime);

    dt[dt.length() - 1] = '\0';
    return dt;
}

std::string Time::getGraphicalTime() const
{
    time_t currentTime = time(0);
    std::string dt = ctime(&currentTime);

    dt[dt.length() - 1] = ' ';
    dt[8] = '\n';
    return dt;
}

void Time::drawModule(sf::RenderWindow &window, Text text)
{
    text.setInfoAndDisplay("    " + getGraphicalTime(), 1230, 190, 20, sf::Color::White, window);
}