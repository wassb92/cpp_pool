/*
** EPITECH PROJECT, 2022
** B-PDG-300-PAR-3-1-PDGD11- ex00
** File description:
** Toy
*/

#ifndef TOY_HPP
#define TOY_HPP

#include <iostream>
#include "Picture.hpp"

class Toy {
public:
    enum ToyType {
        BASIC_TOY,
        ALIEN,
    };

    Toy();
    Toy(ToyType type, const std::string name, const std::string &file);
    ToyType getType() const;
    std::string getName() const;
    void setName(std::string name);
    std::string getAscii() const;
    bool setAscii(std::string);

protected:
private:
    ToyType _type;
    std::string _name;
    bool _ascii;
    Picture _file;
};

#endif /* !TOY_HPP */
