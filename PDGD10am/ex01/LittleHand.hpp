/*
** EPITECH PROJECT, 2022
** B-PDG-300-PAR-3-1-PDGD10am- ex01
** File description:
** LittleHand
*/

#ifndef LITTLEHAND_HPP
#define LITTLEHAND_HPP

#include "FruitBox.hpp"

class LittleHand {
public:
    LittleHand();
    ~LittleHand();
    static void sortFruitBox(FruitBox &unsorted, FruitBox &lemons, FruitBox &bananas, FruitBox &limes);

protected:
private:
};

#endif /* !LITTLEHAND_HPP */
