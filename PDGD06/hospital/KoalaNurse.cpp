/*
** EPITECH PROJECT, 2022
** KoalaNurse
** File description:
** cpp pool day 06 ex 03
*/

#include <fstream>
#include <iostream>
#include "KoalaNurse.hpp"

KoalaNurse::KoalaNurse(int ID)
{
    this->ID = ID;
    this->is_working = false;
}

KoalaNurse::~KoalaNurse()
{
    std::cout << "Nurse " << ID << ": Finally some rest!" << std::endl;
}

void KoalaNurse::giveDrug(std::string drug, SickKoala *sick)
{
    sick->takeDrug(drug);
}

void KoalaNurse::timeCheck(void)
{
    !is_working ? std::cout << "Nurse " << ID
                            << ": Time to get to work!" << std::endl
                : std::cout << "Nurse " << ID
                            << ": Time to go home to my eucalyptus forest!"
                            << std::endl;
    is_working = !is_working;
}

std::string KoalaNurse::readReport(std::string filename)
{
    std::ifstream file(filename);
    char a;

    if (!file.is_open())
        return std::string();

    std::size_t found = filename.find(".report");
    if (found == std::string::npos)
        return std::string();
    std::string drug;
    std::string name = filename.substr(0, filename.find("."));
    while ((a = file.get()) != EOF)
        if (a != '\n')
            drug += a;

    std::cout << "Nurse " << this->ID << ": Kreog! Mr." << name
              << " needs a " << drug << "!" << std::endl;

    return drug;
}

int KoalaNurse::getID(void)
{
    return this->ID;
}
