/*
** EPITECH PROJECT, 2022
** B-PDG-300-PAR-3-1-PDGD08- ex01
** File description:
** DroidMemory
*/

#include "DroidMemory.hpp"

DroidMemory::DroidMemory()
{
    this->Exp = 0;
    this->Fingerprint = random();
}

DroidMemory::~DroidMemory()
{
}

size_t DroidMemory::getFingerPrint() const
{
    return this->Fingerprint;
}

size_t DroidMemory::getExp() const
{
    return this->Exp;
}

void DroidMemory::setFingerPrint(size_t _Fingerprint)
{
    this->Fingerprint = _Fingerprint;
}

void DroidMemory::setExp(size_t _Exp)
{
    this->Exp = _Exp;
}

DroidMemory &DroidMemory::operator<<(DroidMemory const &_DroidMemory)
{
    this->setExp(this->getExp() + _DroidMemory.getExp());
    this->setFingerPrint(this->getFingerPrint() ^ _DroidMemory.getFingerPrint());

    return *this;
}

DroidMemory const &DroidMemory::operator>>(DroidMemory &_DroidMemory) const
{
    _DroidMemory.setExp(getExp() + _DroidMemory.getExp());
    _DroidMemory.setFingerPrint(this->getFingerPrint() ^ _DroidMemory.getFingerPrint());

    return _DroidMemory;
}

DroidMemory &DroidMemory::operator+=(DroidMemory const &_DroidMemory)
{
    return (operator<<(_DroidMemory));
}

DroidMemory &DroidMemory::operator+=(size_t _Exp)
{
    this->setExp(this->getExp() + _Exp);
    this->setFingerPrint(this->getFingerPrint() ^ _Exp);

    return *this;
}

DroidMemory &DroidMemory::operator+(DroidMemory const &_DroidMemory) const
{
    static DroidMemory newDroidMemory;

    newDroidMemory.setExp(this->getExp() + _DroidMemory.getExp());
    newDroidMemory.setFingerPrint(this->getFingerPrint() ^ _DroidMemory.getFingerPrint());

    return newDroidMemory;
}

std::ostream &operator<<(std::ostream &stream, DroidMemory const &droidMemory)
{
    stream << "Droid Memory '" << droidMemory.getFingerPrint() << "', " << droidMemory.getExp();

    return stream;
}
