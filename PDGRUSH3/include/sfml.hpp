/*
** EPITECH PROJECT, 2022
** B-PDG-300-PAR-3-1-PDGRUSH3-
** File description:
** sfml
*/

#ifndef SFML_HPP_
#define SFML_HPP_

#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include "toolbar.hpp"

class Sprite {
public:
    Sprite(int, int);
    ~Sprite();

    sf::Texture texture;
    sf::Sprite sprite;
    int pos_x;
    int pos_y;
};

class Rect {
public:
    Rect();
    ~Rect();

    void setPositionAndDisplay(int, int, sf::RenderWindow &);

    sf::RectangleShape rect;
};

class Text {
public:
    Text();
    ~Text();

    void setInfoAndDisplay(std::string, int, int, size_t, sf::Color, sf::RenderWindow &);

    sf::Font font;
    sf::Text text;
};

int sfmlPage();
void toolbar();
std::vector<Toolbar> ToolTab(const sf::Font &font);
void toolbar_on_click(sf::RenderWindow &window, const sf::Event &event, const sf::Vector2i mouse);

#endif /* !SFML_HPP_ */
