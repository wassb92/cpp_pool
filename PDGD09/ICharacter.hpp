/*
** EPITECH PROJECT, 2022
** c++pool B-PDG-300-PAR-3-1-PDGD09-
** File description:
** ICharacter
*/

#ifndef ICHARACTER_HPP
#define ICHARACTER_HPP

class ICharacter {
public:
    virtual ~ICharacter() {};
    virtual const std::string &getName() const = 0;
    virtual int getPower() const = 0;
    virtual int getHp() const = 0;
    virtual int attack() = 0;
    virtual int special() = 0;
    virtual void rest() = 0;
    virtual void damage(int) = 0;

protected:
private:
};

#endif /* !ICHARACTER_HPP */
