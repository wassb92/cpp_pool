/*
** EPITECH PROJECT, 2022
** SickKoalaList
** File description:
** ex 05 day 06
*/

#ifndef SICKKOALALIST_HPP
#define SICKKOALALIST_HPP

#include "SickKoala.hpp"

class SickKoalaList {
public:
    SickKoalaList(SickKoala *sick);
    ~SickKoalaList();
    bool isEnd(void);
    SickKoala *list { nullptr };
    SickKoalaList *next { nullptr };
    void append(SickKoalaList *sick);
    SickKoala *getFromName(std::string);
    SickKoalaList *remove(SickKoalaList *sick);
    SickKoalaList *removeFromName(std::string);
    SickKoala *getContent();
    SickKoalaList *getNext();
    void dump(void);

protected:
private:
};

#endif /* !SICKKOALALIST_HPP */