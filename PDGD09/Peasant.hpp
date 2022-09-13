/*
** EPITECH PROJECT, 2022
** c++pool B-PDG-300-PAR-3-1-PDGD09-
** File description:
** Peasant
*/

#ifndef PEASANT_HPP
#define PEASANT_HPP

#include <iostream>
#include "ICharacter.hpp"

static const short int MAX_VALUE = 100;

class Peasant : virtual public ICharacter {
public:
    Peasant(const std::string &name, int power);
    virtual ~Peasant();

    const std::string &getName() const;
    int getPower() const;
    int getHp() const;
    int attack();
    int special();
    void rest();
    void damage(int);

    void setName(const std::string &);
    void setPower(int);
    void setHp(int);

protected:
    std::string _name;
    int _power;
    int _hp { MAX_VALUE };

private:
};

#endif /* !PEASANT_HPP */
