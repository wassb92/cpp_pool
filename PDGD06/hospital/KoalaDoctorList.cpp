/*
** EPITECH PROJECT, 2022
** KoalaDoctorList
** File description:
** day 06 ex 05
*/

#include <iostream>
#include "KoalaDoctorList.hpp"
#include "KoalaNurse.hpp"

KoalaDoctorList::KoalaDoctorList(KoalaDoctor *sick)
{
    this->list = sick;
    this->next = nullptr;
}

KoalaDoctorList::~KoalaDoctorList()
{
}

bool KoalaDoctorList::isEnd(void)
{
    return (this->getNext() == nullptr);
}

void KoalaDoctorList::append(KoalaDoctorList *sick)
{
    if (!this->isEnd())
        this->next->append(sick);
    else
        this->next = sick;
}

KoalaDoctor *KoalaDoctorList::getFromName(std::string name)
{
    KoalaDoctorList *tmp = this;

    while (!tmp->isEnd()) {
        if (this->list->getName().compare(name) == 0)
            return this->list;
        tmp = tmp->next;
    }
    return nullptr;
}

KoalaDoctorList *KoalaDoctorList::remove(KoalaDoctorList *sick)
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

KoalaDoctorList *KoalaDoctorList::removeFromName(std::string name)
{
    if (this->list && this->list->getName() == name)
        return this->next;
    if (this->next && this->next->list && this->next->list->getName() == name)
        this->next = this->next->getNext();
    else if (this->next)
        this->next->removeFromName(name);
    return this;
}

KoalaDoctor *KoalaDoctorList::getContent(void)
{
    return this->list;
}

KoalaDoctorList *KoalaDoctorList::getNext(void)
{
    return (!this->next ? nullptr : this->next);
}

void KoalaDoctorList::dump(void)
{
    KoalaDoctorList *tmp = this;

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
