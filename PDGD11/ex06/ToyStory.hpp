/*
** EPITECH PROJECT, 2022
** B-PDG-300-PAR-3-1-PDGD11- ex06
** File description:
** ToyStory
*/

#ifndef TOYSTORY_HPP
#define TOYSTORY_HPP

#include "Toy.hpp"

class ToyStory {
public:
    ToyStory();
    ~ToyStory();
    static void tellMeAStory(const std::string &filename,
        Toy &toy1, bool (Toy::*func1)(const std::string &),
        Toy &toy2, bool (Toy::*func2)(const std::string &));

protected:
private:
};

#endif /* !TOYSTORY_HPP */
