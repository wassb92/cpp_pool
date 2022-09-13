/*
** EPITECH PROJECT, 2022
** c++pool B-PDG-300-PAR-3-1-PDGD09-
** File description:
** Peasant
*/

#include "Peasant.hpp"

Peasant::Peasant(const std::string &name, int power)
{
    this->_name = name;
    this->_power = power;

    std::cout << this->_name << " goes for an adventure." << std::endl;
}

Peasant::~Peasant()
{
    std::cout << this->_name << " is back to his crops." << std::endl;
}

void Peasant::setName(const std::string &name)
{
    this->_name = name;
}

void Peasant::setPower(int power)
{
    this->_power = power;
    if (this->_power >= MAX_VALUE)
        this->_power = MAX_VALUE;
    if (this->_power <= 0)
        this->_power = 0;
}

void Peasant::setHp(int hp)
{
    this->_hp = hp;
    if (this->_hp >= MAX_VALUE)
        this->_hp = MAX_VALUE;
    if (this->_hp <= 0)
        this->_hp = 0;
}

const std::string &Peasant::getName() const
{
    return this->_name;
}

int Peasant::getPower() const
{
    return this->_power;
}

int Peasant::getHp() const
{
    return this->_hp;
}

int Peasant::attack()
{
    if ((this->getPower() - 10) <= 0) {
        std::cout << this->getName() << " is out of power." << std::endl;
        return 0;
    }

    if (this->getHp() <= 0) {
        this->setHp(0);
        std::cout << this->getName() << " is out of combat." << std::endl;
        return 0;
    } else if (this->getPower() <= 0) {
        std::cout << this->getName() << " is out of power." << std::endl;
        this->setPower(0);
    } else {
        this->setPower(this->getPower() - 10);
        std::cout << this->getName() << " tosses a stone." << std::endl;
    }

    return 5;
}

int Peasant::special()
{
    if (this->getHp() <= 0)
        std::cout << this->getName() << " is out of combat." << std::endl;
    else
        std::cout << this->getName() << " doesn't know any special move." << std::endl;

    return 0;
}

void Peasant::rest()
{
    if (this->getHp() <= 0) {
        this->setHp(0);
        std::cout << this->_name << " is out of combat." << std::endl;
        return;
    }
    this->setPower(this->_power + 30);
    std::cout << this->getName() << " takes a nap." << std::endl;
}

void Peasant::damage(int damage)
{
    this->setHp(this->_hp - damage);
    if (this->getHp() <= 0) {
        this->setHp(0);
        std::cout << this->_name << " is out of combat." << std::endl;
        return;
    }
    std::cout << this->getName() << " takes " << damage << " damage." << std::endl;
}
