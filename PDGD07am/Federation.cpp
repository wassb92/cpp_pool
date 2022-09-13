/*
** EPITECH PROJECT, 2022
** c++pool
** File description:
** Federation
*/

#include "Federation.hpp"

Federation::Ship::Ship(int length, int width, std::string name)
{
    this->_length = length;
    this->_width = width;
    this->_name = name;
    this->_location = this->_home;

    std::cout << "The independent ship " + this->_name + " just finished its construction.\n";
    std::cout << "It is " << this->_length << " m in length and " << this->_width << " m in width." << std::endl;
}

Federation::Ship::~Ship()
{
}

Federation::Starfleet::Ship::Ship(int length, int width, std::string name, short maxWarp)
{
    this->_length = length;
    this->_width = width;
    this->_name = name;
    this->_maxWarp = maxWarp;
    this->_location = this->_home;

    std::cout << "The ship USS " + this->_name + " has been finished.\n";
    std::cout << "It is " << this->_length << " m in length and " << this->_width << " m in width.\n";
    std::cout << "It can go to Warp " << this->_maxWarp << "!" << std::endl;
}

Federation::Starfleet::Ship::~Ship()
{
}

void Federation::Starfleet::Ship::setupCore(WarpSystem::Core *_core)
{
    this->core = _core;

    std::cout << "USS " << this->_name << ": The core is set." << std::endl;
}

void Federation::Ship::setupCore(WarpSystem::Core *_core)
{
    this->core = _core;
    std::cout << this->_name << ": The core is set." << std::endl;
}

void Federation::Starfleet::Ship::checkCore()
{
    std::cout << "USS " + _name + ": The core is "
              << (this->core->checkReactor()->isStable()
                         ? "stable"
                         : "unstable")
              << " at the time." << std::endl;
}

void Federation::Ship::checkCore()
{
    std::cout << _name + ": The core is "
              << (this->core->checkReactor()->isStable()
                         ? "stable"
                         : "unstable")
              << " at the time." << std::endl;
}

Federation::Starfleet::Captain::Captain(std::string name)
{
    this->_name = name;
}

Federation::Starfleet::Captain::~Captain()
{
}

std::string Federation::Starfleet::Captain::getName()
{
    return this->_name;
}

int Federation::Starfleet::Captain::getAge()
{
    return this->_age;
}

void Federation::Starfleet::Captain::setAge(int age)
{
    this->_age = age;
}

void Federation::Starfleet::Ship::promote(Captain *captain)
{
    std::cout << captain->getName() << ": I'm glad to be the captain of the USS "
              << this->_name << "." << std::endl;
}

Federation::Starfleet::Ensign::Ensign(std::string name)
{
    this->_name = name;
    std::cout << "Ensign " << this->_name << ", awaiting orders." << std::endl;
}

Federation::Starfleet::Ensign::~Ensign()
{
}

bool Federation::Starfleet::Ship::move(int warp, Destination d)
{
    if (!(warp <= this->_maxWarp && d != _location && this->core->checkReactor()->isStable()))
        return false;
    this->_location = d;
    return true;
}

bool Federation::Starfleet::Ship::move(int warp)
{
    if (move(warp, this->_home)) {
        this->_location = _home;
        return true;
    }
    return false;
}

bool Federation::Starfleet::Ship::move(Destination d)
{
    if (move(this->_maxWarp, d)) {
        this->_location = d;
        return true;
    }
    return false;
}

bool Federation::Starfleet::Ship::move()
{
    if (move(this->_maxWarp, this->_home)) {
        this->_location = _home;
        return true;
    }
    return false;
}

bool Federation::Ship::move(int warp, Destination d)
{
    if (!(warp <= this->_maxWarp && d != _location && this->core->checkReactor()->isStable()))
        return false;
    this->_location = d;
    return true;
}

bool Federation::Ship::move(int warp)
{
    if (move(warp, this->_home)) {
        this->_location = _home;
        return true;
    }
    return false;
}

bool Federation::Ship::move(Destination d)
{
    if (move(this->_maxWarp, d)) {
        this->_location = d;
        return true;
    }
    return false;
}

bool Federation::Ship::move()
{
    if (move(this->_maxWarp, this->_home)) {
        this->_location = _home;
        return true;
    }
    return false;
}