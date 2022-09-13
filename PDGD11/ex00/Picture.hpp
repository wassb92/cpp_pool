/*
** EPITECH PROJECT, 2022
** B-PDG-300-PAR-3-1-PDGD11- ex00
** File description:
** Picture
*/

#ifndef PICTURE_HPP
#define PICTURE_HPP

#include <iostream>

class Picture {
public:
    Picture();
    Picture(const std::string &file);
    std::string data;
    bool getPictureFromFile(const std::string &file);

protected:
private:
};

#endif /* !PICTURE_HPP */
