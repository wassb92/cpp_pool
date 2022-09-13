/*
** EPITECH PROJECT, 2022
** rush3
** File description:
** rush3
*/

#include "MyGKrellm.hpp"

MyGKrellm::MyGKrellm()
{
}

MyGKrellm::~MyGKrellm()
{
}

void MyGKrellm::my_ternimal(void)
{
    int key = '0';
    int page = 0;

    InitTerminal();
    while (key != 'q') {
        all_data.m_core.RefreshInfo();
        all_data.m_ram.RefreshInfo();
        all_data.m_net.RefreshInfo();
        all_data.m_pro.RefreshInfo();
        all_data.m_uptime.RefreshInfo();
        change_page(key, page);
        printInfo(all_data, page);
        key = getch();
        refresh();
        clear();
    }
    endwin();
}