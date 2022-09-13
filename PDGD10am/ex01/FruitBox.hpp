/*
** EPITECH PROJECT, 2022
** B-PDG-300-PAR-3-1-PDGD10am- ex00
** File description:
** FruitBox
*/

#ifndef FRUITBOX_HPP
#define FRUITBOX_HPP

#include "FruitNode.hpp"
#include "Fruit.hpp"

class FruitBox {
public:
    FruitBox(int size);
    int nbFruits() const;
    bool putFruit(Fruit *f);
    Fruit *pickFruit();
    FruitNode *head() const;
    int _len { 0 };

protected:
private:
    FruitNode *headFruit { NULL };
    int _size;
};

#endif /* !FRUITBOX_HPP */
