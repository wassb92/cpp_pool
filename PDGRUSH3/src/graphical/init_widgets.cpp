/*
** EPITECH PROJECT, 2022
** B-PDG-300-PAR-3-1-PDGRUSH3-
** File description:
** init_widgets
*/

#include "sfml.hpp"

Sprite::Sprite(int pos_x, int pos_y)
{
    this->texture.loadFromFile("src/graphical/assets/card.png");
    this->sprite.setTexture(this->texture);
    this->sprite.setPosition(pos_x, pos_y);
}

Sprite::~Sprite()
{
}

Rect::Rect()
{
    sf::RectangleShape rect(sf::Vector2f(350, 300));
    rect.setFillColor(sf::Color::Black);
    rect.setOutlineColor(sf::Color::White);
    rect.setOutlineThickness(3);
    this->rect = rect;
}

Rect::~Rect()
{
}

void Rect::setPositionAndDisplay(int pos_x, int pos_y, sf::RenderWindow &window)
{
    this->rect.setPosition(pos_x, pos_y);
    window.draw(this->rect);
}

Text::Text()
{
    this->font.loadFromFile("src/graphical/fonts/FiraCode.ttf");
    this->text.setFont(this->font);
}

Text::~Text()
{
}

void Text::setInfoAndDisplay(std::string str, int pos_x, int pos_y, size_t size, sf::Color color, sf::RenderWindow &window)
{
    this->text.setFont(this->font);
    this->text.setString(str);
    this->text.setCharacterSize(size);
    this->text.setFillColor(color);
    this->text.setPosition(pos_x, pos_y);
    window.draw(this->text);
}