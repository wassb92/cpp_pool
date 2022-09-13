/*
** EPITECH PROJECT, 2022
** ex 04 cpp pool
** File description:
** KoalaDoctor
*/

#ifndef KOALADOCTOR_HPP
#define KOALADOCTOR_HPP

#include "SickKoala.hpp"

class KoalaDoctor {
public:
    KoalaDoctor(std::string);
    ~KoalaDoctor();
    std::string name;
    std::string patientName;
    bool is_working;
    void diagnose(SickKoala *sick);
    void timeCheck(void);
    std::string getName();

protected:
private:
};

#endif /* !KOALADOCTOR_HPP */