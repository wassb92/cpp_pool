/*
** EPITECH PROJECT, 2022
** day 05
** File description:
** append
*/

#include <string.h>
#include <stdlib.h>
#include "string.h"

char at(const string_t *this, size_t pos)
{
    if (pos >= strlen(this->str))
        return -1;
    return this->str[pos];
}