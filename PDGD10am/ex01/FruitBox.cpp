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

int FruitBox::nbFruits() const
{
    return this->_len;
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
        ++this->_len;
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
    ++this->_len;
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
    --this->_len;
    delete tmpNode;

    return tmpFruit;
}

FruitNode *FruitBox::head() const
{
    return (this->headFruit);
}
