/*
** EPITECH PROJECT, 2022
** B-PDG-300-PAR-3-1-PDGD07pm- ex02
** File description:
** KreogCom
*/

#include "KreogCom.hpp"

KreogCom::KreogCom(int x, int y, int serial)
    : m_serial(serial)
{
    this->_x = x;
    this->_y = y;
    this->next = nullptr;

    std::cout << "KreogCom " << this->m_serial << " initialized" << std::endl;
}

KreogCom::~KreogCom()
{
    std::cout << "KreogCom " << this->m_serial << " shutting down" << std::endl;
}

void KreogCom::addCom(int x, int y, int serial)
{
    KreogCom *newKreog = new KreogCom(x, y, serial);

    if (!newKreog)
        return;

    newKreog->next = this->next;
    this->next = newKreog;
}

KreogCom *KreogCom::getCom()
{
    return (!this->next ? nullptr : this->next);
}

void KreogCom::removeCom()
{
    KreogCom *tmp = nullptr;

    if (!this->next)
        return;
    tmp = this->next;
    this->next = this->next->next;
    delete tmp;
}

void KreogCom::ping()
{
    if (this->next != nullptr)
        std::cout << "KreogCom " << this->next->m_serial << " currently at "
                  << this->next->_x << " " << this->next->_y << std::endl;
    if (this->next->next != nullptr)
        std::cout << "KreogCom " << this->next->next->m_serial << " currently at "
                  << this->next->next->_x << " " << this->next->next->_y << std::endl;
    std::cout << "KreogCom " << this->m_serial << " currently at "
              << this->_x << " " << this->_y << std::endl;
}

void KreogCom::locateSquad()
{
    this->ping();
}
