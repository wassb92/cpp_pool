/*
** EPITECH PROJECT, 2022
** src graphical
** File description:
** toolbar
*/

#include <iostream>
#include <SFML/Window/Mouse.hpp>
#include "const.hpp"
#include "toolbar.hpp"

Toolbar::Toolbar(const sf::Font &font, const std::string &str, const unsigned short pos)
{
    unsigned short pos_to_draw = pos == 0 ? 50 : 187.5 * pos + 50;
    pos_to_draw += 5;

    text.setFont(font);
    text.setString(str);
    text.setFillColor(sf::Color::White);
    text.setStyle(sf::Text::Bold | sf::Text::Underlined);
    text.setPosition(pos_to_draw, 800);
}

Toolbar::~Toolbar()
{
}

sf::Text Toolbar::getText() const
{
    return text;
}

void draw_pipe(sf::RenderWindow &window, const unsigned short pos)
{
    const unsigned short pos_to_draw = pos == 0 ? 50 : 187.5 * pos + 50;

    sf::RectangleShape line(sf::Vector2f(150, 5));
    line.rotate(90);
    line.setPosition(pos_to_draw, 800);
    window.draw(line);
}

void draw_toolbar(sf::RenderWindow &window, const Toolbar &toolbar)
{
    for (unsigned short i = 0; i < MAX_MODULE; ++i)
        draw_pipe(window, i);

    window.draw(toolbar.getText());
}

std::vector<Toolbar> ToolTab(const sf::Font &font)
{
    unsigned short pos = 0;

    Toolbar Monitor(font, "CPU", pos++);
    Toolbar Name(font, "Hostname\nUsername", pos++);
    Toolbar OS(font, "OS Name\nKernel V", pos++);
    Toolbar Time(font, "Date\nTime", pos++);
    Toolbar RAM(font, "RAM", pos++);
    Toolbar Network(font, "Network\nload", pos++);
    Toolbar Uptime(font, "Uptime", pos++);
    Toolbar Process(font, "Process", pos++);

    std::vector<Toolbar> vec { Monitor, Name, OS, Time, Process, RAM, Network, Uptime };

    return vec;
}