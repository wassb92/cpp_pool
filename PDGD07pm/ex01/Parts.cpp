/*
** EPITECH PROJECT, 2022
** B-PDG-300-PAR-3-1-PDGD07pm- ex01
** File description:
** Parts
*/

#include "Parts.hpp"

Arms::Arms(std::string const serial, bool functional)
{
    this->_serial = serial;
    this->_functional = functional;
}

Arms::~Arms()
{
}

bool Arms::isFunctional() const
{
    return this->_functional;
}

std::string Arms::serial() const
{
    return this->_serial;
}

void Arms::informations() const
{
    std::cout << "\t[Parts] "
              << "Arms " << this->serial() << " status : "
              << (this->isFunctional() ? "OK" : "KO") << std::endl;
}

Legs::Legs(std::string const serial, bool functional)
{
    this->_serial = serial;
    this->_functional = functional;
}

Legs::~Legs()
{
}

bool Legs::isFunctional() const
{
    return this->_functional;
}

std::string Legs::serial() const
{
    return this->_serial;
}

void Legs::informations() const
{
    std::cout << "\t[Parts] "
              << "Legs " << this->serial() << " status : "
              << (this->isFunctional() ? "OK" : "KO") << std::endl;
}

Head::Head(std::string const serial, bool functional)
{
    this->_serial = serial;
    this->_functional = functional;
}

Head::~Head()
{
}

bool Head::isFunctional() const
{
    return this->_functional;
}

std::string Head::serial() const
{
    return this->_serial;
}

void Head::informations() const
{
    std::cout << "\t[Parts] "
              << "Head " << this->serial() << " status : "
              << (this->isFunctional() ? "OK" : "KO") << std::endl;
}
