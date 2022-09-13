/*
** EPITECH PROJECT, 2022
** B-PDG-300-PAR-3-1-PDGD07pm- ex01
** File description:
** KoalaBot
*/

#include "KoalaBot.hpp"

KoalaBot::KoalaBot(const std::string serial)
{
    this->_serial = serial;
}

KoalaBot::~KoalaBot()
{
}

void KoalaBot::informations() const
{
    std::cout << "[KoalaBot] " << this->_serial << std::endl;

    this->_arms.informations();
    this->_legs.informations();
    this->_head.informations();
}

void KoalaBot::setParts(const Arms &arms)
{
    this->_arms = arms;
}

void KoalaBot::setParts(const Legs &legs)
{
    this->_legs = legs;
}

void KoalaBot::setParts(const Head &head)
{
    this->_head = head;
}

void KoalaBot::swapParts(Arms &arms)
{
    Arms tmp = arms;

    arms = this->_arms;
    this->_arms = tmp;
}

void KoalaBot::swapParts(Legs &legs)
{
    Legs tmp = legs;

    legs = this->_legs;
    this->_legs = tmp;
}

void KoalaBot::swapParts(Head &head)
{
    Head tmp = head;

    head = this->_head;
    this->_head = tmp;
}

bool KoalaBot::status() const
{
    return (this->_arms.isFunctional() && this->_legs.isFunctional() && this->_head.isFunctional());
}