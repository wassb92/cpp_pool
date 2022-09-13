/*
** EPITECH PROJECT, 2022
** B-PDG-300-PAR-3-1-PDGD11- ex02
** File description:
** Woody
*/

#ifndef WOODY_HPP
#define WOODY_HPP

#include "Toy.hpp"

class Woody : public Toy {
public:
    Woody(std::string, std::string);
    Woody(std::string);
    ~Woody();
    bool speak(const std::string &);

protected:
private:
};

#endif /* !WOODY_HPP */
