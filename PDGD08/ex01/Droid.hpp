/*
** EPITECH PROJECT, 2022
** B-PDG-300-PAR-3-1-PDGD08- ex00
** File description:
** Droid
*/

#ifndef DROID_HPP
#define DROID_HPP

#include <iostream>
#include "DroidMemory.hpp"

class Droid {
public:
    Droid(std::string);
    Droid(const Droid &);
    ~Droid();

    Droid &operator=(Droid const &droid);
    bool operator==(const Droid &droid) const;
    bool operator!=(const Droid &droid) const;
    Droid &operator<<(size_t &energy);

    std::string getId() const;
    size_t getEnergy() const;
    size_t getAttack() const;
    size_t getToughness() const;
    std::string *getStatus() const;
    DroidMemory *getBattleData();

    void setId(std::string);
    void setEnergy(size_t);
    void setStatus(std::string *);
    void setBattleData(DroidMemory *);

protected:
private:
    std::string Id { "" };
    size_t Energy;
    const size_t Attack;
    const size_t Toughness;
    std::string *Status;
    DroidMemory *BattleData;
};

std::ostream &operator<<(std::ostream &stream, Droid const &droid);

#endif /* !DROID_HPP */
