/*
** EPITECH PROJECT, 2022
** B-PDG-300-PAR-3-1-PDGD10am- ex01
** File description:
** LittleHand
*/

#include "LittleHand.hpp"

LittleHand::LittleHand()
{
}

LittleHand::~LittleHand()
{
}

void LittleHand::sortFruitBox(FruitBox &unsorted, FruitBox &lemons, FruitBox &bananas, FruitBox &limes)
{
    Fruit *fruit = NULL;
    FruitBox tmp(unsorted.nbFruits());

    for (; (fruit = unsorted.pickFruit());)
        tmp.putFruit(fruit);

    while ((fruit = tmp.pickFruit())) {
        if (fruit->getVitamins() == 5 && fruit->getName() == "banana") {
            if (!bananas.putFruit(fruit))
                unsorted.putFruit(fruit);
            continue;
        }
        if (fruit->getVitamins() == 3 && fruit->getName() == "lemon") {
            if (!lemons.putFruit(fruit))
                unsorted.putFruit(fruit);
            continue;
        }
        if (fruit->getVitamins() == 2 && fruit->getName() == "lime") {
            if (!limes.putFruit(fruit))
                unsorted.putFruit(fruit);
            continue;
        }
    }
}
