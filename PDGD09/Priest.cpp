/*
** EPITECH PROJECT, 2022
** c++pool B-PDG-300-PAR-3-1-PDGD09-
** File description:
** Priest
*/

#include "Priest.hpp"
#include "Enchanter.hpp"

Priest::Priest(const std::string &name, int power)
    : Peasant(name, power)
    , Enchanter(name, power)

{
    this->_name = name;
    this->_power = power;
    std::cout << this->_name << " enters in the order." << std::endl;
}

Priest::~Priest()
{
    std::cout << this->_name << " finds peace." << std::endl;
}

void Priest::rest()
{
    if (this->getHp() <= 0) {
        std::cout << this->_name << " is out of combat." << std::endl;
        return;
    }
    this->setPower(100);
    this->setHp(100);
    std::cout << this->getName() << " prays." << std::endl;
}
