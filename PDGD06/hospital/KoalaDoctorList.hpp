/*
** EPITECH PROJECT, 2022
** KoalaDoctorList
** File description:
** ex 05 day 06
*/

#ifndef KOALADOCTORLIST_HPP
#define KOALADOCTORLIST_HPP

#include "KoalaDoctor.hpp"

class KoalaDoctorList {
public:
    KoalaDoctorList(KoalaDoctor *sick);
    ~KoalaDoctorList();
    bool isEnd(void);
    KoalaDoctor *list { nullptr };
    KoalaDoctorList *next { nullptr };
    void append(KoalaDoctorList *sick);
    KoalaDoctor *getFromName(std::string);
    KoalaDoctorList *remove(KoalaDoctorList *sick);
    KoalaDoctorList *removeFromName(std::string);
    KoalaDoctor *getContent();
    KoalaDoctorList *getNext();
    void dump(void);

protected:
private:
};

#endif /* !SICKKOALALIST_HPP */