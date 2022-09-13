/*
** EPITECH PROJECT, 2022
** src modules
** File description:
** Uptime
*/

#ifndef UPTIME_HPP
#define UPTIME_HPP

#include <iostream>
#include <vector>
#include "IMonitorModule.hpp"

class Uptime : virtual public IMonitorModule {
public:
    void RefreshInfo();
    size_t uptimeFromFile;
    tm *upTime;

    sf::RectangleShape rect;
    sf::RectangleShape rect2;

    void drawModule(sf::RenderWindow &window, Text text);
};

std::vector<std::string> getFileContent(std::string const &file);
std::vector<std::string> stringToVec(const std::string &str, const std::string &pattern);

#endif /* !UPTIME_HPP */
