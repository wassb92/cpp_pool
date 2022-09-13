/*
** EPITECH PROJECT, 2022
** SickKoalaList
** File description:
** day 06 ex 05
*/

#include <iostream>
#include "SickKoalaList.hpp"
#include "KoalaNurse.hpp"

SickKoalaList::SickKoalaList(SickKoala *sick)
{
    this->list = sick;
    this->next = nullptr;
}

SickKoalaList::~SickKoalaList()
{
}

bool SickKoalaList::isEnd(void)
{
    return (this->getNext() == nullptr);
}

void SickKoalaList::append(SickKoalaList *sick)
{
    if (!this->isEnd())
        this->next->append(sick);
    else
        this->next = sick;
}

SickKoala *SickKoalaList::getFromName(std::string name)
{
    SickKoalaList *tmp = this;

    while (!tmp->isEnd()) {
        if (this->list->getName().compare(name) == 0)
            return this->list;
        tmp = tmp->next;
    }
    return nullptr;
}

SickKoalaList *SickKoalaList::remove(SickKoalaList *sick)
{
    if (sick != nullptr) {
        if (this == sick)
            return this->next;
        if (this->next == sick)
            this->next = this->next->getNext();
        else
            this->next->remove(sick);
    }
    return this;
}

SickKoalaList *SickKoalaList::removeFromName(std::string name)
{
    if (this->list && this->list->getName() == name)
        return this->next;
    if (this->next && this->next->list && this->next->list->getName() == name)
        this->next = this->next->getNext();
    else if (this->next)
        this->next->removeFromName(name);
    return this;
}

SickKoala *SickKoalaList::getContent(void)
{
    return this->list;
}

SickKoalaList *SickKoalaList::getNext(void)
{
    return (!this->next ? nullptr : this->next);
}

void SickKoalaList::dump(void)
{
    SickKoalaList *tmp = this;

    std::cout << "Patients: ";

    while (tmp != nullptr) {
        if (tmp->list == nullptr)
            std::cout << "nullptr";
        else
            std::cout << tmp->list->getName();
        if (tmp->next)
            std::cout << ", ";
        tmp = tmp->getNext();
    }
    std::cout << "." << std::endl;
}
