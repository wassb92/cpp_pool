/*
** EPITECH PROJECT, 2022
** ex 04 cpp pool
** File description:
** KoalaDoctor
*/

#include <iostream>
#include <fstream>
#include <vector>
#include "KoalaDoctor.hpp"
#include "KoalaNurse.hpp"
#include "SickKoala.hpp"

KoalaDoctor::KoalaDoctor(std::string name)
{
    this->name = name;
    this->is_working = false;

    std::cout << "Dr." << this->name << ": I'm Dr."
              << this->name << "! How do you kreog?" << std::endl;
}

KoalaDoctor::~KoalaDoctor()
{
}

void KoalaDoctor::diagnose(SickKoala *sick)
{
    this->patientName = sick->getName();
    std::cout << "Dr." << name << ": So what's goerking you Mr."
              << this->patientName << "?" << std::endl;
    sick->poke();
    std::string filename = patientName + ".report";
    std::ofstream create_file(filename);
    std::vector<std::string> drug { "Mars", "Kinder", "Crunch", "Maroilles", "Eucalyptus leaf" };

    create_file << drug[random() % 5] << std::endl;

    create_file.close();
}

void KoalaDoctor::timeCheck(void)
{
    !is_working ? std::cout
            << "Dr." + name + ": Time to get to work\n"
                : std::cout << "Dr." + name
                + ": Time to go home to my eucalyptus forest!"
                            << std::endl;
    is_working = !is_working;
}

std::string KoalaDoctor::getName()
{
    return this->name;
}
