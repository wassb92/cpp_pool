/*
** EPITECH PROJECT, 2022
** day 06
** File description:
** the nurse
*/

#ifndef SICKKOALA_HPP_
#define SICKKOALA_HPP_

#include <string>

class SickKoala {
public:
    SickKoala(std::string);
    ~SickKoala();
    std::string name;
    bool takeDrug(std::string);
    void poke(void);
    void overDrive(std::string);
    std::string getName(void);

protected:
private:
};

#endif /* !SICKKOALA_HPP_ */