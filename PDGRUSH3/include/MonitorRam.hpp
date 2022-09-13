/*
** EPITECH PROJECT, 2022
** B-PDG-300-PAR-3-1-PDGRUSH3-
** File description:
** MonitorRam
*/

#ifndef MONITORRAM_HPP_
#define MONITORRAM_HPP_

#include <iostream>
#include <vector>
#include "IMonitorModule.hpp"

class MonitorRam : virtual public IMonitorModule {
public:
    void RefreshInfo();
    int m_memTotal;
    int m_memFree;
    int m_memAvailable;
    int m_memBuffers;
    int m_memCached;
    int m_memUsed;
    int m_memUsage;

    sf::RectangleShape rect;
    sf::RectangleShape rect2;

    void updateRect();
    void drawModule(sf::RenderWindow &window, Text text);
};

std::vector<std::string> getFileContent(std::string const &file);
std::vector<std::string> stringToVec(const std::string &str, const std::string &pattern);

#endif /* !MONITORRAM_HPP_ */
