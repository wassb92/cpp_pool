/*
** EPITECH PROJECT, 2022
** B-PDG-300-PAR-3-1-PDGD07pm- ex01
** File description:
** Parts
*/

#ifndef PARTS_HPP
#define PARTS_HPP

#include <iostream>

class Arms {
public:
    Arms(std::string const serial = "A-01", bool functional = true);
    ~Arms();
    bool isFunctional() const;
    std::string serial() const;
    void informations() const;

private:
    std::string _serial;
    bool _functional;
};

class Legs {
public:
    Legs(std::string const serial = "L-01", bool functional = true);
    ~Legs();
    bool isFunctional() const;
    std::string serial() const;
    void informations() const;

private:
    std::string _serial;
    bool _functional;
};

class Head {
public:
    Head(std::string const serial = "H-01", bool functional = true);
    ~Head();
    bool isFunctional() const;
    std::string serial() const;
    void informations() const;

private:
    std::string _serial;
    bool _functional;
};

#endif /* !PARTS_HPP */
