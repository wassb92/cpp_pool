/*
** EPITECH PROJECT, 2022
** day 05
** File description:
** empty
*/

#include <string.h>
#include <stdlib.h>
#include "string.h"

int empty(const string_t *this)
{
    return (!this || !this->str || this->str[0] == '\0');
}