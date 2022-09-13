/*
** EPITECH PROJECT, 2022
** B-PDG-300-PAR-3-1-PDGD08- ex00
** File description:
** Droid
*/

#include "Droid.hpp"

Droid::Droid(std::string Id)
    : Energy(50)
    , Attack(25)
    , Toughness(15)
    , Status(new std::string("Standing by"))
{
    this->BattleData = new DroidMemory();
    this->Id = Id;
    std::cout << "Droid \'" << this->Id << "\' Activated" << std::endl;
}

Droid::Droid(const Droid &droid)
    : Id(droid.Id)
    , Energy(droid.Energy)
    , Attack(droid.Attack)
    , Toughness(droid.Toughness)
    , Status(new std::string(*droid.Status))
{
    this->BattleData = nullptr;
    std::cout << "Droid \'" << this->Id << "\' Activated, Memory Dumped" << std::endl;
}

Droid::~Droid()
{
    std::cout << "Droid "
              << "\'" << this->Id << "\'"
              << " Destroyed" << std::endl;
    if (this->Status)
        delete this->Status;
    if (this->BattleData)
        delete this->BattleData;
}

std::string Droid::getId() const
{
    return (this->Id);
}

size_t Droid::getEnergy() const
{
    return (this->Energy);
}

size_t Droid::getAttack() const
{
    return (this->Attack);
}

size_t Droid::getToughness() const
{
    return (this->Toughness);
}

std::string *Droid::getStatus() const
{
    return (this->Status);
}

DroidMemory *Droid::getBattleData()
{
    return this->BattleData;
}

void Droid::setId(std::string Id)
{
    this->Id = Id;
}

void Droid::setEnergy(size_t Energy)
{
    this->Energy = Energy;
    if (this->Energy > 100)
        this->Energy = 100;
}

void Droid::setStatus(std::string *Status)
{
    if (this->Status)
        delete this->Status;

    this->Status = Status;
}

void Droid::setBattleData(DroidMemory *_BattleData)
{
    delete this->BattleData;
    this->BattleData = _BattleData;
}

Droid &Droid::operator=(Droid const &droid)
{
    this->Id = droid.Id;
    this->Energy = droid.Energy;

    return *this;
}

bool Droid::operator==(const Droid &droid) const
{
    return (*this->getStatus() == *droid.getStatus());
}

bool Droid::operator!=(const Droid &droid) const
{
    return (!(this->operator==(droid)));
}

Droid &Droid::operator<<(size_t &energy)
{
    if (this->getEnergy() + energy > 100) {
        energy -= (100 - this->getEnergy());
        this->setEnergy(100);
    } else {
        this->setEnergy(this->getEnergy() + energy);
        energy = 0;
    }

    return (*this);
}

std::ostream &operator<<(std::ostream &stream, const Droid &droid)
{
    stream << "Droid \'" << droid.getId() << "\', "
           << *(droid.getStatus()) << ", " << droid.getEnergy();

    return stream;
}