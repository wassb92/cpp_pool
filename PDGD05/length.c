/*
** EPITECH PROJECT, 2022
** day 05
** File description:
** clear
*/

#include <string.h>
#include <stdlib.h>
#include "string.h"

int length(const string_t *this)
{
    int i = 0;

    if (!this || !this->str)
        return i;
    while (this->str[++i]);

    return i;
}