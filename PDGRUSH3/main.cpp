/*
** EPITECH PROJECT, 2022
** B-PDG-300-PAR-3-1-PDGRUSH3- src
** File description:
** main
*/

#include "const.hpp"
#include "MyGKrellm.hpp"
#include "sfml.hpp"
#include <iostream>
#include <ncurses.h>

static bool error_handling(int ac, char const **av)
{
    if (ac != 2)
        return true;
    if (std::string(av[1]) != TEXT_MODE && std::string(av[1]) != GRAPHICAL_MODE)
        return true;
    return false;
}

int main(int ac, char const **av)
{
    MyGKrellm info;
    if (error_handling(ac, av))
        EXIT_ERROR;
    if ((std::string(av[1]) == TEXT_MODE))
        info.my_ternimal();
    if ((std::string(av[1]) == GRAPHICAL_MODE))
        sfmlPage();
    return EXIT_SUCCESS;
}
