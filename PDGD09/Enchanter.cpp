/*
** EPITECH PROJECT, 2022
** c++pool B-PDG-300-PAR-3-1-PDGD09-
** File description:
** Enchanter
*/

#include "Enchanter.hpp"

Enchanter::Enchanter(const std::string &name, int power)
    : Peasant(name, power)
{
    this->_name = name;
    this->_power = power;
    std::cout << this->_name << " learns magic from his spellbook." << std::endl;
}

Enchanter::~Enchanter()
{
    std::cout << this->_name << " closes his spellbook." << std::endl;
}

int Enchanter::attack()
{
    if (this->getHp() <= 0) {
        std::cout << this->_name << " is out of combat." << std::endl;
        return 0;
    }

    std::cout << this->getName() << " doesn't know how to fight." << std::endl;

    return 0;
}

int Enchanter::special()
{
    if (this->getHp() <= 0) {
        std::cout << this->_name << " is out of combat." << std::endl;
        return 0;
    }
    if (this->getPower() - 50 <= 0) {
        std::cout << this->getName() << " is out of power." << std::endl;
        return 0;
    }
    this->setPower(this->_power - 50);
    if (this->getPower() <= 0) {
        std::cout << this->getName() << " is out of power." << std::endl;
        return 0;
    }

    std::cout << this->getName() << " casts a fireball." << std::endl;

    return 99;
}

void Enchanter::rest()
{
    if (this->getHp() <= 0) {
        std::cout << this->_name << " is out of combat." << std::endl;
        return;
    }
    this->setPower(this->_power + 100);
    std::cout << this->getName() << " meditates." << std::endl;
}
