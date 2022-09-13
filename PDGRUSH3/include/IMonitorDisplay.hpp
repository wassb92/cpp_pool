/*
** EPITECH PROJECT, 2022
** B-PDG-300-PAR-3-1-PDGRUSH3-
** File description:
** IMonitorDisplay
*/

#ifndef IMONITORDISPLAY_HPP_
#define IMONITORDISPLAY_HPP_

#include "IMonitorModule.hpp"

class IMonitorDisplay {
public:
    IMonitorDisplay() {};
    virtual ~IMonitorDisplay() {};
    virtual void drawAllModules(IMonitorModule &module, sf::RenderWindow &window, Text text) = 0;
};

class DisplayModule : public IMonitorDisplay {
public:
    DisplayModule() { }
    virtual ~DisplayModule() { }

    void drawAllModules(IMonitorModule &module, sf::RenderWindow &window, Text text) { module.drawModule(window, text); }
};

#endif /* !IMONITORDISPLAY_HPP_ */
