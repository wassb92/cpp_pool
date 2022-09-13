/*
** EPITECH PROJECT, 2022
** B-PDG-300-PAR-3-1-PDGD10am- ex00
** File description:
** Fruit
*/

#include "Fruit.hpp"

Fruit::Fruit(std::string const &name, int vitamins)
{
    this->_name = name;
    this->_vitamins = vitamins;
}

Fruit::~Fruit()
{
}

std::string Fruit::getName() const
{
    return this->_name;
}

int Fruit::getVitamins() const
{
    return this->_vitamins;
}
