/*
** EPITECH PROJECT, 2022
** B-PDG-300-PAR-3-1-PDGD10am- ex00
** File description:
** Fruit
*/

#ifndef FRUIT_HPP
#define FRUIT_HPP

#include <iostream>

class Fruit {
public:
    Fruit(std::string const &name, int vitamins);
    virtual ~Fruit();

    virtual std::string getName() const;
    virtual int getVitamins() const;

protected:
    int _vitamins;
    std::string _name;

private:
};

#endif /* !FRUIT_HPP */
