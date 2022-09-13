/*
** EPITECH PROJECT, 2022
** rush3
** File description:
** rush3
*/

#ifndef NET_H
#define NET_H

#include <iostream>
#include <vector>
#include "IMonitorModule.hpp"

class Netinfo {
public:
    std::string name;
    size_t ReciveBt;
    size_t TransmitBt;
    size_t RecivePaket;
    size_t TransmitPaket;
};

class MonitorNet : virtual public IMonitorModule, public Netinfo {
public:
    int numberProgram;
    void RefreshInfo();
    void drawModule(sf::RenderWindow &window, Text text);
    std::vector<Netinfo> program;

private:
    sf::RectangleShape rect;
    sf::RectangleShape rect2;
};

std::vector<std::string> stringToVec(const std::string &str, const std::string &pattern);
std::vector<std::string> getFileContent(std::string const &file);

#endif /* !NET_H */
