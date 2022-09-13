/*
** EPITECH PROJECT, 2022
** rush3
** File description:
** rush3
*/

#ifndef MYGK_H
#define MYGK_H

#include "SystemInfo.hpp"
#include <ncurses.h>

class MyGKrellm {
    public:
        MyGKrellm();
        ~MyGKrellm();
        void my_ternimal();
    private:
        SystemInfo all_data;
        bool is_ternimal;
};

void printInfo(SystemInfo const &all_data, int const &);
void InitTerminal();
void change_page(int key, int &page);

#endif /* !MYGK_H */
