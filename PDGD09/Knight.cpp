/*
** EPITECH PROJECT, 2022
** c++pool B-PDG-300-PAR-3-1-PDGD09-
** File description:
** Knight
*/

#include "Knight.hpp"

Knight::Knight(const std::string &name, int power)
    : Peasant(name, power)
{
    this->_name = name;
    this->_power = power;

    std::cout << this->_name << " vows to protect the kingdom." << std::endl;
}
Knight::~Knight()
{
    std::cout << this->_name << " takes off his armor." << std::endl;
}

int Knight::attack()
{
    if (this->getHp() <= 0) {
        std::cout << this->_name << " is out of combat." << std::endl;
        return 0;
    }

    if (this->getPower() - 10 <= 0) {
        std::cout << this->getName() << " is out of power." << std::endl;
        return 0;
    }
    this->setPower(this->_power - 10);

    if (this->getPower() <= 0) {
        std::cout << this->getName() << " is out of power." << std::endl;
        return 0;
    }
    std::cout << this->getName() << " strikes with his sword." << std::endl;

    return 20;
}

int Knight::special()
{
    if (this->getHp() <= 0) {
        std::cout << this->_name << " is out of combat." << std::endl;
        return 0;
    }
    if (this->getPower() - 30 <= 0) {
        std::cout << this->getName() << " is out of power." << std::endl;
        return 0;
    }
    if (this->getPower() <= 0) {
        std::cout << this->getName() << " is out of power." << std::endl;
        return 0;
    }
    this->setPower(this->_power - 30);

    std::cout << this->getName() << " impales his enemy." << std::endl;

    return 50;
}

void Knight::rest()
{
    if (this->getHp() <= 0) {
        std::cout << this->_name << " is out of combat." << std::endl;
        return;
    }
    this->setPower(this->_power + 50);
    std::cout << this->getName() << " eats." << std::endl;
}
