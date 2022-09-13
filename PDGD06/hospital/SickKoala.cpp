/*
** EPITECH PROJECT, 2022
** cpp pool day 06
** File description:
** ex 2 the nurse
*/

#include <iostream>
#include <regex>
#include "SickKoala.hpp"

SickKoala::SickKoala(std::string name)
{
    this->name = name;
}

SickKoala::~SickKoala()
{
    std::cout << "Mr." << name << ": Kreooogg!! I'm cuuuured!" << std::endl;
}

void SickKoala::poke(void)
{
    std::cout << "Mr." << name << ": Gooeeeeerrk!!" << std::endl;
}

bool SickKoala::takeDrug(std::string str)
{
    if (str != "Mars" && str != "Kinder") {
        std::cout << "Mr." << name << ": Goerkreog!" << std::endl;
        return false;
    }
    if (str == "Mars")
        std::cout << "Mr." << name << ": Mars, and it kreogs!" << std::endl;
    if (str == "Kinder")
        std::cout << "Mr." << name << ": There is a toy inside!" << std::endl;
    return true;
}

void SickKoala::overDrive(std::string str)
{
    str = std::regex_replace(str, std::regex("Kreog!"), "1337!");

    std::cout << "Mr." << name << ": " << str << std::endl;
}

std::string SickKoala::getName(void)
{
    return this->name;
}
