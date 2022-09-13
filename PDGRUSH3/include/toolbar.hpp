/*
** EPITECH PROJECT, 2022
** B-PDG-300-PAR-3-1-PDGRUSH3- include
** File description:
** toolbar
*/

#ifndef TOOLBAR_HPP
#define TOOLBAR_HPP

#include <SFML/Graphics.hpp>

class Toolbar {
public:
    Toolbar(const sf::Font &font, const std::string &str, const unsigned short pos);
    ~Toolbar();

    sf::Text getText() const;

private:
    sf::Text text;
};

class BoolToDispMod {
public:
    BoolToDispMod() { }
    ~BoolToDispMod() { }
    bool CPU = true;
    bool names = true;
    bool OS = true;
    bool dateTime = true;
    bool RAM = true;
    bool network = true;
    bool uptime = true;
    bool process = true;
    sf::Vector2i mouse;

    bool toolbar_on_click(sf::RenderWindow &window, int pos_x);
    void toolbar_set_Display(sf::RenderWindow &window);
    void set_all();
};

void draw_toolbar(sf::RenderWindow &window, const Toolbar &toolbar);

#endif /* !TOOLBAR_HPP */
