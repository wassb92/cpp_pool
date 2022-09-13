/*
** EPITECH PROJECT, 2022
** c++pool B-PDG-300-PAR-3-1-PDGD09-
** File description:
** Priest
*/

#ifndef PRIEST_HPP
#define PRIEST_HPP

#include "Enchanter.hpp"

class Priest : virtual public Enchanter {
public:
    Priest(const std::string &name, int power);
    virtual ~Priest();
    void rest();

protected:
private:
};

#endif /* !PRIEST_HPP */
