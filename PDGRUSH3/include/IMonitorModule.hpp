/*
** EPITECH PROJECT, 2022
** B-PDG-300-PAR-3-1-PDGRUSH3-
** File description:
** IMonitorModule
*/

#ifndef IMONITORMODULE_HPP_
#define IMONITORMODULE_HPP_

#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include "sfml.hpp"

class IMonitorModule {
public:
    IMonitorModule() { }
    virtual ~IMonitorModule() { }

    virtual void drawModule(sf::RenderWindow &window, Text text) = 0;
};

#endif /* !IMONITORMODULE_HPP_ */
