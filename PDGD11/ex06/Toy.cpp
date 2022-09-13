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
    if (this->_file.getPictureFromFile(filename))
        return true;
    else {
        this->errorObj.type = Error::PICTURE;
        return false;
    }
}

std::string Toy::getAscii() const
{
    return (this->_file.data);
}

bool Toy::speak(const std::string &str)
{
    std::cout << this->getName() << " \"" << str << "\"" << std::endl;

    return true;
}

std::ostream &operator<<(std::ostream &stream, const Toy &toy)
{
    stream << toy.getName() << "\n"
           << toy.getAscii() << std::endl;

    return stream;
}

Toy &Toy::operator<<(std::string str)
{
    this->_file.data = str;

    return *this;
}

bool Toy::speak_es(const std::string &str)
{
    (void)str;
    this->errorObj.type = Error::SPEAK;
    return false;
}

std::string Toy::Error::what() const
{
    if (this->type == PICTURE)
        return "bad new illustration";
    if (this->type == SPEAK)
        return "wrong mode";
    return "";
}

std::string Toy::Error::where() const
{
    if (this->type == PICTURE)
        return "setAscii";
    if (this->type == SPEAK)
        return "speak_es";
    return "";
}

Toy::Error Toy::getLastError() const
{
    return this->errorObj;
}
