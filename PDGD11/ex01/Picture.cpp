/*
** EPITECH PROJECT, 2022
** B-PDG-300-PAR-3-1-PDGD11- ex00
** File description:
** Picture
*/

#include "Picture.hpp"
#include <fstream>

Picture::Picture()
{
    this->data = "";
}

Picture::Picture(const std::string &file)
{
    getPictureFromFile(file);

    if (this->data == "")
        this->data = "ERROR";
}

bool Picture::getPictureFromFile(const std::string &file)
{
    std::ifstream filename(file);

    if (!filename.is_open()) {
        this->data = "ERROR";
        return false;
    }
    if (!getline(filename, this->data, '\0')) {
        this->data = "ERROR";
        return false;
    }
    return true;
}
