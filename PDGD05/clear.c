/*
** EPITECH PROJECT, 2022
** day 05
** File description:
** clear
*/

#include <string.h>
#include <stdlib.h>
#include "string.h"

void clear(string_t *this)
{
    memset(this->str, 0, strlen(this->str));
}