/*
** EPITECH PROJECT, 2022
** B-PDG-300-PAR-3-1-PDGD07pm- ex03
** File description:
** Phaser
*/

#ifndef PHASER_HPP
#define PHASER_HPP

#include <iostream>
#include "Sounds.hpp"

class Phaser {
public:
    enum AmmoType {
        REGULAR,
        PLASMA,
        ROCKET
    };
    Phaser(int maxAmmo = 20, AmmoType type = REGULAR);
    ~Phaser();
    void fire();
    void ejectClip();
    void changeType(AmmoType newType);
    void reload();
    void addAmmo(AmmoType type);
    int getCurrentAmmos();

private:
    static const int Empty = 0;
    int _maxAmmo;
    AmmoType _type;
    static const unsigned int ammoLen = 3;
    int _magazine[ammoLen];
    Sounds sound;
};

#endif /* !PHASER_HPP */
