/*
** EPITECH PROJECT, 2022
** day 05
** File description:
** to_int
*/

#include <string.h>
#include <stdlib.h>
#include "string.h"

int to_int(const string_t *this)
{
    return atoi(this->str);
}