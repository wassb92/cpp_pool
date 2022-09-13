/*
** EPITECH PROJECT, 2022
** KoalaNurseList
** File description:
** ex 05 day 06
*/

#ifndef KOALANURSELIST_HPP
#define KOALANURSELIST_HPP

#include "KoalaNurse.hpp"

class KoalaNurseList {
public:
    KoalaNurseList(KoalaNurse *sick);
    ~KoalaNurseList();
    bool isEnd(void);
    KoalaNurse *list { nullptr };
    KoalaNurseList *next { nullptr };
    void append(KoalaNurseList *sick);
    KoalaNurse *getFromID(int);
    KoalaNurseList *remove(KoalaNurseList *sick);
    KoalaNurseList *removeFromID(int);
    KoalaNurse *getContent();
    KoalaNurseList *getNext();
    void dump(void);

protected:
private:
};

#endif /* !SICKKOALALIST_HPP */