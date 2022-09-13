/*
** EPITECH PROJECT, 2022
** B-PDG-300-PAR-3-1-PDGD11- ex02
** File description:
** Woody
*/

#include "Woody.hpp"

Woody::Woody(std::string name, std::string file)
    : Toy(Woody::WOODY, name, file)
{
}

Woody::Woody(std::string name)
    : Toy(Woody::WOODY, name, "woody.txt")
{
}

Woody::~Woody()
{
}

bool Woody::speak(const std::string &str)
{
    std::cout << "WOODY: " << this->getName() << " \"" << str << "\"" << std::endl;

    return true;
}
