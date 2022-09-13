/*
** EPITECH PROJECT, 2022
** B-PDG-300-PAR-3-1-PDGD10am- ex00
** File description:
** FruitNode
*/

#ifndef FRUITNODE_HPP
#define FRUITNODE_HPP

#include "Fruit.hpp"

typedef struct FruitNode_s {
    Fruit *fruitData;
    struct FruitNode_s *next;
} FruitNode;

#endif /* !FRUITNODE_HPP */
