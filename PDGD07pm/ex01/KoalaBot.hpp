/*
** EPITECH PROJECT, 2022
** B-PDG-300-PAR-3-1-PDGD07pm- ex01
** File description:
** KoalaBot
*/

#ifndef KOALABOT_HPP
#define KOALABOT_HPP

#include <iostream>
#include "Parts.hpp"

class KoalaBot {
public:
    KoalaBot(std::string serial = "Bob-01");
    ~KoalaBot();
    void setParts(const Arms &_arms);
    void setParts(const Legs &_legs);
    void setParts(const Head &_head);

    void swapParts(Arms &_arms);
    void swapParts(Legs &_legs);
    void swapParts(Head &_head);

    void informations() const;
    bool status() const;

protected:
private:
    Arms _arms;
    Legs _legs;
    Head _head;

    std::string _serial;
};

#endif /* !KOALABOT_HPP */
