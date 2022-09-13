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
        BUZZ,
        WOODY
    };

    Toy();
    Toy(ToyType type, const std::string name, const std::string &file);
    Toy(const Toy &other);
    Toy &operator=(const Toy &other);
    ToyType getType() const;
    std::string getName() const;
    void setName(std::string name);
    std::string getAscii() const;
    virtual void speak(const std::string);
    Toy &operator<<(std::string);
    bool setAscii(std::string);
    virtual bool speak_es(const std::string);
    class Error {
    public:
        std::string what() const;
        std::string where() const;
        enum ErrorType {
            UNKNOWN,
            PICTURE,
            SPEAK
        };
        ErrorType type;
    };
    Error getLastError() const;

protected:
private:
    ToyType _type;
    std::string _name;
    Picture _file;
    Error errorObj;
};

std::ostream &operator<<(std::ostream &, const Toy &);

#endif /* !TOY_HPP */
