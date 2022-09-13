/*
** EPITECH PROJECT, 2022
** c++pool B-PDG-300-PAR-3-1-PDGD09-
** File description:
** Enchanter
*/

#ifndef ENCHANTER_HPP
#define ENCHANTER_HPP

#include "Peasant.hpp"

class Enchanter : virtual public Peasant {
public:
    Enchanter(const std::string &name, int power);
    virtual ~Enchanter();
    int attack();
    int special();
    void rest();

protected:
private:
};

#endif /* !ENCHANTER_HPP */
