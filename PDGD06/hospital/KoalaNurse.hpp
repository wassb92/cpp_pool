/*
** EPITECH PROJECT, 2022
** KoalaNurse
** File description:
** ex 03 day 06
*/

#ifndef KOALANURSE_HPP
#define KOALANURSE_HPP

#include <string>
#include "SickKoala.hpp"

class KoalaNurse {
public:
    KoalaNurse(int ID);
    ~KoalaNurse();
    int ID;
    bool is_working { false };
    void destroy_koala_nurse(void);
    void giveDrug(std::string, SickKoala *sick);
    std::string readReport(std::string);
    void timeCheck(void);
    int getID();

protected:
private:
};

#endif /* !KOALANURSE_HPP */