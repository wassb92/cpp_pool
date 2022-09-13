/*
** EPITECH PROJECT, 2022
** B-PDG-300-PAR-3-1-PDGRUSH3-
** File description:
** MonitorRam
*/

#include "const.hpp"
#include "MonitorRam.hpp"

void MonitorRam::updateRect()
{
    sf::RectangleShape rect(sf::Vector2f(250, 20));
    rect.setFillColor(sf::Color::Black);
    rect.setOutlineColor(sf::Color::White);
    rect.setOutlineThickness(2);
    rect.setPosition(120, 560);
    this->rect = rect;

    float f = 2.5 * ((this->m_memUsed * 100) / this->m_memTotal);
    sf::RectangleShape rect2(sf::Vector2f(f, 20));
    rect2.setFillColor(sf::Color::White);
    rect2.setPosition(120, 560);
    this->rect2 = rect2;
}

void MonitorRam::RefreshInfo()
{
    std::vector<std::string> memInfo = getFileContent("/proc/meminfo");
    std::vector<std::string> vec;

    for (size_t i = 0; i < memInfo.size(); ++i) {
        if (memInfo[i].find("MemTotal:") != std::string::npos) {
            vec = stringToVec(memInfo[i], ":");
            m_memTotal = atoi(vec[1].c_str());
        }
        if (memInfo[i].find("MemFree:") != std::string::npos) {
            vec = stringToVec(memInfo[i], ":");
            m_memFree = atoi(vec[1].c_str());
        }
        if (memInfo[i].rfind("MemAvailable:", 0) == 0) {
            vec = stringToVec(memInfo[i], ":");
            m_memAvailable = atoi(vec[1].c_str());
        }
        if (memInfo[i].rfind("Cached:", 0) == 0) {
            vec = stringToVec(memInfo[i], ":");
            m_memCached = atoi(vec[1].c_str());
            break;
        }
        if (memInfo[i].find("Buffers:") != std::string::npos) {
            vec = stringToVec(memInfo[i], ":");
            m_memBuffers = atoi(vec[1].c_str());
        }
    }
    m_memUsed = m_memTotal - m_memAvailable;
    m_memUsage = (m_memUsed * 100 / m_memTotal);
    updateRect();
}

void MonitorRam::drawModule(sf::RenderWindow &window, Text text)
{
    RefreshInfo();
    text.setInfoAndDisplay("Total Memory: " + std::to_string(this->m_memTotal) + " Ko", 120, 430, 13, sf::Color::White, window);
    text.setInfoAndDisplay("Free Memory: " + std::to_string(this->m_memFree) + " Ko", 120, 450, 13, sf::Color::White, window);
    text.setInfoAndDisplay("Available Memory: " + std::to_string(this->m_memAvailable) + " Ko", 120, 470, 13, sf::Color::White, window);
    text.setInfoAndDisplay("Used Memory: " + std::to_string(this->m_memUsed) + " Ko", 120, 490, 13, sf::Color::White, window);
    text.setInfoAndDisplay("Cached Memory: " + std::to_string(this->m_memCached) + " Ko", 120, 510, 13, sf::Color::White, window);
    window.draw(this->rect);
    window.draw(this->rect2);
    float f = ((this->m_memUsed * 100) / this->m_memTotal);
    text.setInfoAndDisplay(std::to_string((int)f) + "%", 390, 560, 16, sf::Color::White, window);
}