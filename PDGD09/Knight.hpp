/*
** EPITECH PROJECT, 2022
** c++pool B-PDG-300-PAR-3-1-PDGD09-
** File description:
** Knight
*/

#include "Peasant.hpp"

#ifndef KNIGHT_HPP
#define KNIGHT_HPP

class Knight : virtual public Peasant {
public:
    Knight(const std::string &name, int power);
    virtual ~Knight();
    virtual int attack();
    int special();
    void rest();

protected:
private:
};

#endif /* !KNIGHT_HPP */
