/*
** EPITECH PROJECT, 2022
** include informations
** File description:
** Time
*/

#ifndef TIME_HPP_
#define TIME_HPP_

#include <iostream>
#include <ctime>
#include "IMonitorModule.hpp"

class Time : virtual public IMonitorModule {
public:
    std::string getTime() const;
    std::string getGraphicalTime() const;

    void drawModule(sf::RenderWindow &window, Text text);
};

#endif /* !TIME_HPP */
