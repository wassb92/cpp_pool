/*
** EPITECH PROJECT, 2022
** c++pool B-PDG-300-PAR-3-1-PDGD09-
** File description:
** Paladin
*/

#include "Paladin.hpp"

Paladin::Paladin(const std::string &name, int power)
    : Peasant(name, power)
    , Knight(name, power)
    , Enchanter(name, power)
    , Priest(name, power)
{
    this->_name = name;
    this->_power = power;

    std::cout << this->_name << " fights for the light." << std::endl;
}

Paladin::~Paladin()
{
    std::cout << this->_name << " is blessed." << std::endl;
}

int Paladin::attack()
{
    return Knight::attack();
}

int Paladin::special()
{
    return Enchanter::special();
}

void Paladin::rest()
{
    Priest::rest();
}