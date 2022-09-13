/*
** EPITECH PROJECT, 2022
** rush3
** File description:
** rush3
*/

#include "MonitorNet.hpp"

void MonitorNet::RefreshInfo()
{
    numberProgram = 0;
    std::vector<Netinfo>().swap(program);
    std::vector<std::string> AllNetInfo = getFileContent("/proc/net/dev");
    std::vector<std::string> vec;
    Netinfo data;

    for (size_t i = 2; i < AllNetInfo.size(); ++i) {
        vec = stringToVec(AllNetInfo[i].c_str(), " ");
        data.name = vec[0].c_str();
        data.ReciveBt = atoi(vec[1].c_str());
        data.RecivePaket = atoi(vec[2].c_str());
        data.TransmitBt = atoi(vec[9].c_str());
        data.TransmitPaket = atoi(vec[10].c_str());
        ++numberProgram;
        program.push_back(data);
    };
    this->name = data.name;
    this->ReciveBt = data.ReciveBt;
    this->TransmitBt = data.TransmitBt;
    this->RecivePaket = data.RecivePaket;
    this->TransmitPaket = data.TransmitPaket;
}

void MonitorNet::drawModule(sf::RenderWindow &window, Text text)
{
    float y_pos = 450;
    const float x_pos = 480;
    const float text_size = 16;
    RefreshInfo();
    text.setInfoAndDisplay("Name: " + (name.back() == ':' ? name.substr(0, name.size() - 1) : name), x_pos, y_pos, text_size, sf::Color::White, window);
    text.setInfoAndDisplay("Bytes received: " + std::to_string(ReciveBt), x_pos, y_pos + 35, text_size, sf::Color::White, window);
    text.setInfoAndDisplay("Bytes transmitted: " + std::to_string(TransmitBt), x_pos, y_pos + 70, text_size, sf::Color::White, window);
    text.setInfoAndDisplay("Packets received: " + std::to_string(RecivePaket), x_pos, y_pos + 105, text_size, sf::Color::White, window);
    text.setInfoAndDisplay("Packs transmitted: " + std::to_string(TransmitPaket), x_pos, y_pos + 140, text_size, sf::Color::White, window);
    window.draw(this->rect);
    window.draw(this->rect2);
}
