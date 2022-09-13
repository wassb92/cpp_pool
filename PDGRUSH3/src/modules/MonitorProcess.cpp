/*
** EPITECH PROJECT, 2022
** rush3
** File description:
** rush3
*/

#include "MonitorProcess.hpp"

static const std::string getCmdResult(const std::string &str)
{
    char buff[2048] = { 0 };
    FILE *fl = NULL;

    fl = popen(str.c_str(), "r");
    if (fl == NULL)
        return "";
    std::string res;
    while (fgets(buff, sizeof buff, fl)) {
        res += buff;
    }
    pclose(fl);
    return res;
}

void MonitorProcess::RefreshInfo()
{
    programList = stringToVec(getCmdResult("ps -au"), "\n");
}

void MonitorProcess::drawModule(sf::RenderWindow &window, Text text)
{
    RefreshInfo();
    int sizeMax = this->programList.size() > 10 ? 10 : this->programList.size() - this->indexPos;

    for (int i = this->indexPos, pos_y = 450, t = 0; t < sizeMax; i++, pos_y += 20, t++)
        text.setInfoAndDisplay(this->programList[i], 1180, pos_y, 11, sf::Color::White, window);
}