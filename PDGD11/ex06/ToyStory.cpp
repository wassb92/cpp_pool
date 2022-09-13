/*
** EPITECH PROJECT, 2022
** B-PDG-300-PAR-3-1-PDGD11- ex06
** File description:
** ToyStory
*/

#include <fstream>
#include "ToyStory.hpp"

ToyStory::ToyStory()
{
}

ToyStory::~ToyStory()
{
}

void print_error(Toy &toy)
{
    std::cout << toy.getLastError().where() << ": " << toy.getLastError().what() << std::endl;
}

static bool find_picture(std::string const &tmp, std::ifstream &file, std::string &line,
    Toy &toy, bool (Toy::*func)(const std::string &))
{
    if (!(toy.setAscii(tmp)))
        return false;
    std::cout << toy.getAscii() << std::endl;
    if (!file.eof()) {
        getline(file, line);
        if (!(toy.*func)(line))
            return false;
    }
    return true;
}

bool isPicture(std::string fileLine, std::string &picture, bool isToyOne, std::ifstream &file, Toy &toy1, bool (Toy::*func1)(const std::string &), Toy &toy2, bool (Toy::*func2)(const std::string &))
{
    picture = fileLine.substr(8);
    if (isToyOne)
        if (!find_picture(picture, file, fileLine, toy1, func1)) {
            print_error(toy1);
            return false;
        }
    if (!isToyOne)
        if (!find_picture(picture, file, fileLine, toy2, func2)) {
            print_error(toy2);
            return false;
        }
    return true;
}

bool execute_fct()
{
    return true;
}

void ToyStory::tellMeAStory(const std::string &filename, Toy &toy1, bool (Toy::*func1)(const std::string &), Toy &toy2, bool (Toy::*func2)(const std::string &))
{
    std::string fileLine;
    bool isToyOne = true;
    std::ifstream file(filename);
    std::string picture;

    if (!file.is_open()) {
        std::cout << "Bad Story" << std::endl;
        return;
    }
    std::cout << toy1.getAscii() << "\n"
              << toy2.getAscii() << std::endl;
    for (unsigned int i = 0; (!file.eof()); ++i) {
        getline(file, fileLine);
        if (file.fail())
            return;
        if (fileLine.substr(0, 8) == "picture:") {
            if (!(isPicture(fileLine, picture, isToyOne, file, toy1, func1, toy2, func2)))
                return;
        } else {
            if (isToyOne) {
                if (!(toy1.*func1)(fileLine)) {
                    print_error(toy1);
                    return;
                }
            } else if (!isToyOne) {
                if (!(toy2.*func2)(fileLine)) {
                    print_error(toy2);
                    return;
                }
            }
        }
        if (isToyOne == true)
            isToyOne = false;
        else if (isToyOne == false)
            isToyOne = true;
    }
}
