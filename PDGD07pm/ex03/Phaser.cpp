/*
** EPITECH PROJECT, 2022
** B-PDG-300-PAR-3-1-PDGD07pm- ex03
** File description:
** Phaser
*/

#include <vector>
#include "Phaser.hpp"

Phaser::Phaser(int maxAmmo, AmmoType type)
{
    this->_maxAmmo = maxAmmo;

    for (unsigned int i = 0; i < ammoLen; ++i)
        _magazine[i] = _maxAmmo;
    if (type > ammoLen - 1)
        type = REGULAR;
    this->_type = type;
}

Phaser::~Phaser()
{
}

void Phaser::fire()
{
    if (this->_magazine[this->_type] == Empty) {
        std::cout << "Clip empty, please reload" << std::endl;
        return;
    }
    if (this->_type == REGULAR)
        std::cout << Sounds::Regular << std::endl;
    if (this->_type == PLASMA)
        std::cout << Sounds::Plasma << std::endl;
    if (this->_type == ROCKET)
        std::cout << Sounds::Rocket << std::endl;

    this->_magazine[this->_type] -= 1;
}

void Phaser::ejectClip()
{
    this->_magazine[this->_type] = Empty;
}

void Phaser::changeType(AmmoType newType)
{
    if (newType > ROCKET)
        return;
    this->_type = newType;
    std::vector<std::string> enum_as_string { "regular", "plasma", "rocket" };

    std::cout << "Switching ammo to type: " << enum_as_string[this->_type] << std::endl;
}

void Phaser::reload()
{
    std::cout << "Reloading..." << std::endl;

    this->_magazine[this->_type] = this->_maxAmmo;
}

void Phaser::addAmmo(AmmoType type)
{
    if (type > ROCKET)
        return;

    if (this->_magazine[this->_type] == this->_maxAmmo) {
        std::cout << "Clip full" << std::endl;
        return;
    }
    ++this->_magazine[this->_type];
}

int Phaser::getCurrentAmmos()
{
    return this->_magazine[this->_type];
}
