/*
** EPITECH PROJECT, 2022
** B-PDG-300-PAR-3-1-PDGD11- ex00
** File description:
** Toy
*/

#include "Toy.hpp"

Toy::Toy()
{
    this->_type = BASIC_TOY;
    this->setName("toy");
    this->_file.data = "";
}

Toy::Toy(ToyType type, const std::string name, const std::string &file)
{
    this->_type = type;
    this->_name = name;
    this->_file = file;
}

Toy::Toy(const Toy &other) = default;

Toy &Toy::operator=(const Toy &other)
{
    this->_type = other._type;
    this->_name = other._name;
    this->_file = other._file;

    return *this;
}

Toy::ToyType Toy::getType() const
{
    return this->_type;
}

std::string Toy::getName() const
{
    return this->_name;
}

void Toy::setName(std::string name)
{
    this->_name = name;
}

bool Toy::setAscii(std::string filename)
{
    return (this->_file.getPictureFromFile(filename));
}

std::string Toy::getAscii() const
{
    return (this->_file.data);
}

void Toy::speak(const std::string str)
{
    std::cout << this->getName() << " \"" << str << "\"" << std::endl;
}
