/*
** EPITECH PROJECT, 2022
** B-PDG-300-PAR-3-1-PDGD11- ex02
** File description:
** Buzz
*/

#ifndef BUZZ_HPP
#define BUZZ_HPP

#include "Toy.hpp"

class Buzz : public Toy {
public:
    Buzz(std::string, std::string);
    Buzz(std::string);
    ~Buzz();
    bool speak(const std::string &);
    bool speak_es(const std::string &);

protected:
private:
};

#endif /* !BUZZ_HPP */
