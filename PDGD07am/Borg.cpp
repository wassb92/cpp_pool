/*
** EPITECH PROJECT, 2022
** c++pool
** File description:
** Borg
*/

#include "Borg.hpp"

Borg::Ship::Ship()
{
    this->_location = this->_home;

    std::cout << "We are the Borgs. Lower your shields and surrender yourselves unconditionally.\n"
              << "Your biological characteristics and technologies will be assimilated.\n"
              << "Resistance is futile." << std::endl;
}

Borg::Ship::~Ship()
{
}

Borg::Core::Core()
{
    std::cout << (this->_stability ? "Everything is in order."
                                   : "Critical failure imminent.")
              << std::endl;
}

Borg::Core::~Core()
{
}

void Borg::Ship::setupCore(WarpSystem::Core *_core)
{
    this->core = _core;
}

void Borg::Ship::checkCore(void)
{
    std::cout << (this->core->checkReactor()->isStable()
            ? "Everything is in order."
            : "Critical failure imminent.")
              << std::endl;
}

bool Borg::Ship::move(int warp, Destination d)
{
    if (!(warp <= this->_maxWarp && d != _location && this->core->checkReactor()->isStable()))
        return false;
    this->_location = d;
    return true;
}

bool Borg::Ship::move(int warp)
{
    if (move(warp, this->_home)) {
        this->_location = _home;
        return true;
    }
    return false;
}

bool Borg::Ship::move(Destination d)
{
    if (move(this->_maxWarp, d)) {
        this->_location = d;
        return true;
    }
    return false;
}

bool Borg::Ship::move()
{
    if (move(this->_maxWarp, this->_home)) {
        this->_location = _home;
        return true;
    }
    return false;
}