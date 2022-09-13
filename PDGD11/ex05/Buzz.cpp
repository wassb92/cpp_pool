/*
** EPITECH PROJECT, 2022
** B-PDG-300-PAR-3-1-PDGD11- ex02
** File description:
** Buzz
*/

#include "Buzz.hpp"

Buzz::Buzz(std::string name, std::string file)
    : Toy(Buzz::BUZZ, name, file)
{
}

Buzz::Buzz(std::string name)
    : Toy(Buzz::BUZZ, name, "buzz.txt")
{
}

Buzz::~Buzz()
{
}

void Buzz::speak(const std::string str)
{
    std::cout << "BUZZ: " << this->getName() << " \"" << str << "\"" << std::endl;
}

bool Buzz::speak_es(const std::string str)
{
    std::cout << "BUZZ: " << this->getName() << " senorita \"" << str << "\" senorita" << std::endl;

    return true;
}