/*
** EPITECH PROJECT, 2022
** c++pool B-PDG-300-PAR-3-1-PDGD09-
** File description:
** Paladin
*/

#ifndef PALADIN_HPP
#define PALADIN_HPP

#include "Knight.hpp"
#include "Priest.hpp"

class Paladin : virtual public Knight, virtual public Priest {
public:
    explicit Paladin(const std::string &name, int power);
    virtual ~Paladin();

    int attack();
    int special();
    void rest();

protected:
private:
};

#endif /* !PALADIN_HPP */
