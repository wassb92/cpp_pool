/*
** EPITECH PROJECT, 2022
** B-PDG-300-PAR-3-1-PDGD08- ex00
** File description:
** Droid
*/

#ifndef DROID_HPP
#define DROID_HPP

#include <iostream>

class Droid {
public:
    Droid();
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

    void setId(std::string);
    void setEnergy(size_t);
    void setStatus(std::string *);

protected:
private:
    std::string Id { "" };
    size_t Energy;
    const size_t Attack;
    const size_t Toughness;
    std::string *Status;
};

std::ostream &operator<<(std::ostream &stream, const Droid &droid);

#endif /* !DROID_HPP */
