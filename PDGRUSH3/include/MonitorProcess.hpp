/*
** EPITECH PROJECT, 2022
** rush3
** File description:
** rush3
*/

#ifndef MPORC_H
#define MPORC_H

#include <iostream>
#include <vector>
#include "IMonitorModule.hpp"

class MonitorProcess : public virtual IMonitorModule{
public:
	void RefreshInfo();
    std::vector<std::string> programList;

    int indexPos = 0;

    void drawModule(sf::RenderWindow &window, Text text);
};

std::vector<std::string> getFileContent(std::string const &file);
std::vector<std::string> stringToVec(const std::string &str, const std::string &pattern);

#endif /* !MPORC_H */
