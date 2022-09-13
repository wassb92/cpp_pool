/*
** EPITECH PROJECT, 2022
** B-PDG-300-PAR-3-1-PDGD10am- ex00
** File description:
** FruitBox
*/

#include "FruitBox.hpp"

FruitBox::FruitBox(int size)
{
    this->_size = size;
}

int FruitBox::nbFruits()
{
    int i = 0;
    FruitNode *node = this->headFruit;

    if (!node)
        return i;

    for (; node; ++i, node = node->next) { }

    return i;
}

bool FruitBox::putFruit(Fruit *f)
{
    if (!f || (this->nbFruits() > this->_size) || (this->_size < 0))
        return false;
    FruitNode *tmp = new FruitNode;
    FruitNode *node = this->headFruit;

    if (!tmp)
        return false;
    tmp->fruitData = f;
    tmp->next = nullptr;

    if (!node) {
        this->headFruit = tmp;
        return true;
    }
    if (f->getName() == this->headFruit->fruitData->getName()) {
        delete tmp;
        return false;
    }
    for (; node->next; node = node->next) {
        if (f->getName() == this->headFruit->fruitData->getName()) {
            delete tmp;
            return false;
        }
    }
    node->next = tmp;

    return true;
}

Fruit *FruitBox::pickFruit()
{
    FruitNode *tmpNode;
    Fruit *tmpFruit;

    if (!this->headFruit)
        return NULL;
    tmpNode = this->headFruit;
    tmpFruit = this->headFruit->fruitData;

    this->headFruit = this->headFruit->next;
    delete tmpNode;

    return tmpFruit;
}

FruitNode *FruitBox::head()
{
    return (this->nbFruits() == 0 ? NULL : this->headFruit);
}
