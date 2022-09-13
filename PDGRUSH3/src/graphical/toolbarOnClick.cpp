/*
** EPITECH PROJECT, 2022
** rush 03
** File description:
** onclick toolbar
*/

#include "toolbar.hpp"
#include <iostream>

bool BoolToDispMod::toolbar_on_click(sf::RenderWindow &window, int pos_x)
{
    if (sf::Mouse::isButtonPressed(sf::Mouse::Left)
        && (mouse.x >= pos_x && mouse.x <= pos_x + 180)
        && (mouse.y >= 800 && mouse.y <= 900))
        return true;
    return false;
}

void BoolToDispMod::set_all()
{
    if (this->CPU && this->names && this->OS && this->dateTime && this->RAM && this->network) {
        this->CPU = false;
        this->names = false;
        this->OS = false;
        this->dateTime = false;
        this->RAM = false;
        this->network = false;
        this->uptime = false;
        this->process = false;
    } else {
        this->CPU = true;
        this->names = true;
        this->OS = true;
        this->dateTime = true;
        this->RAM = true;
        this->network = true;
        this->uptime = true;
        this->process = true;
    }
}

void BoolToDispMod::toolbar_set_Display(sf::RenderWindow &window)
{
    this->mouse = sf::Mouse::getPosition(window);
    if (toolbar_on_click(window, 50) == true)
        this->CPU = !this->CPU;
    if (toolbar_on_click(window, 237) == true)
        this->names = !this->names;
    if (toolbar_on_click(window, 424) == true)
        this->OS = !this->OS;
    if (toolbar_on_click(window, 611) == true)
        this->dateTime = !this->dateTime;
    if (toolbar_on_click(window, 798) == true)
        this->RAM = !this->RAM;
    if (toolbar_on_click(window, 985) == true)
        this->network = !this->network;
    if (toolbar_on_click(window, 1145) == true)
        this->uptime = !this->uptime;
    if (toolbar_on_click(window, 1335) == true)
        this->process = !this->process;
}
