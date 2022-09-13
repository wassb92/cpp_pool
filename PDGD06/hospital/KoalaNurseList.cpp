/*
** EPITECH PROJECT, 2022
** KoalaNurseList
** File description:
** day 06 ex 05
*/

#include <iostream>
#include "KoalaNurseList.hpp"
#include "KoalaNurse.hpp"

KoalaNurseList::KoalaNurseList(KoalaNurse *koala)
{
    this->list = koala;
    this->next = nullptr;
}

KoalaNurseList::~KoalaNurseList()
{
}

bool KoalaNurseList::isEnd(void)
{
    return (this->getNext() == nullptr);
}

void KoalaNurseList::append(KoalaNurseList *koala)
{
    if (!this->isEnd())
        this->next->append(koala);
    else
        this->next = koala;
}

KoalaNurse *KoalaNurseList::getFromID(int ID)
{
    KoalaNurseList *tmp = this;

    while (!tmp->isEnd()) {
        if (this->list->getID() == ID)
            return this->list;
        tmp = tmp->next;
    }
    return nullptr;
}

KoalaNurseList *KoalaNurseList::remove(KoalaNurseList *koala)
{
    if (koala != nullptr) {
        if (this == koala)
            return this->next;
        if (this->next == koala)
            this->next = this->next->getNext();
        else
            this->next->remove(koala);
    }
    return this;
}

KoalaNurseList *KoalaNurseList::removeFromID(int ID)
{
    if (this->list && this->list->getID() == ID)
        return this->next;
    if (this->next && this->next->list && this->next->list->getID() == ID)
        this->next = this->next->getNext();
    else if (this->next)
        this->next->removeFromID(ID);
    return this;
}

KoalaNurse *KoalaNurseList::getContent(void)
{
    return this->list;
}

KoalaNurseList *KoalaNurseList::getNext(void)
{
    return (!this->next ? nullptr : this->next);
}

void KoalaNurseList::dump(void)
{
    KoalaNurseList *tmp = this;

    std::cout << "Patients: ";

    while (tmp != nullptr) {
        if (tmp->list == nullptr)
            std::cout << "nullptr";
        else
            std::cout << tmp->list->getID();
        if (tmp->next)
            std::cout << ", ";
        tmp = tmp->getNext();
    }
    std::cout << "." << std::endl;
}
