/*
** EPITECH PROJECT, 2022
** B-PDG-300-PAR-3-1-PDGD07pm- ex02
** File description:
** KreogCom
*/

#ifndef KREOGCOM_HPP
#define KREOGCOM_HPP

#include <iostream>

class KreogCom {
public:
    KreogCom(int x, int y, int serial);
    ~KreogCom();
    void addCom(int x, int y, int serial);
    void removeCom();
    KreogCom *getCom();
    void ping();
    void locateSquad();

private:
    const int m_serial;
    int _x;
    int _y;
    KreogCom *next;
};

#endif /* !KREOGCOM_HPP */
