/*
** EPITECH PROJECT, 2022
** src modules
** File description:
** Uptime
*/

#include "Uptime.hpp"

void Uptime::RefreshInfo()
{
    std::vector<std::string> memInfo = getFileContent("/proc/uptime");
    std::vector<std::string> vec;

    std::string sec = memInfo[0].substr(0, memInfo[0].find(' '));

    uptimeFromFile = stoi(sec);

    time_t seconds(uptimeFromFile);
    upTime = gmtime(&seconds);
}

void Uptime::drawModule(sf::RenderWindow &window, Text text)
{
    RefreshInfo();
    text.setInfoAndDisplay(std::to_string(upTime->tm_yday) + "\tDays", 820, 450, 18, sf::Color::White, window);
    text.setInfoAndDisplay(std::to_string(upTime->tm_hour) + "\tHours", 820, 480, 18, sf::Color::White, window);
    text.setInfoAndDisplay(std::to_string(upTime->tm_min) + "\tMinutes", 820, 510, 18, sf::Color::White, window);
    text.setInfoAndDisplay(std::to_string(upTime->tm_sec) + "\tSeconds", 820, 540, 18, sf::Color::White, window);
    window.draw(this->rect);
    window.draw(this->rect2);
}
