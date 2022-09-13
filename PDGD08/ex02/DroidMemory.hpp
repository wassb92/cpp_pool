/*
** EPITECH PROJECT, 2022
** B-PDG-300-PAR-3-1-PDGD08- ex01
** File description:
** DroidMemory
*/

#ifndef DROIDMEMORY_HPP
#define DROIDMEMORY_HPP

#include <iostream>

class DroidMemory {
public:
    DroidMemory();
    ~DroidMemory();

    size_t getFingerPrint() const;
    size_t getExp() const;

    void setFingerPrint(size_t);
    void setExp(size_t);

    DroidMemory &operator<<(DroidMemory const &right);
    DroidMemory const &operator>>(DroidMemory &right) const;
    DroidMemory &operator+=(DroidMemory const &right);
    DroidMemory &operator+=(size_t exp);
    DroidMemory &operator+(DroidMemory const &right) const;
    DroidMemory &operator+(size_t exp) const;

protected:
private:
    size_t Fingerprint;
    size_t Exp;
};

std::ostream &operator<<(std::ostream &stream, DroidMemory const &droidMemory);

#endif /* !DROIDMEMORY_HPP */
