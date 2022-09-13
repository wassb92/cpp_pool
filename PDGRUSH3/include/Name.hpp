/*
** EPITECH PROJECT, 2022
** include informations
** File description:
** Name
*/

#ifndef NAME_HPP
#define NAME_HPP

#include <iostream>
#include <unistd.h>
#include "IMonitorModule.hpp"
#include "sfml.hpp"

class Name : virtual public IMonitorModule {
public:
	std::string getHostName() const;
    std::string getUserName() const;
    void drawModule(sf::RenderWindow &window, Text text);
};

#endif /* !NAME_HPP */