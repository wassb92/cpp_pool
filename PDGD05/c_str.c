/*
** EPITECH PROJECT, 2022
** day 05
** File description:
** c_str
*/

#include <string.h>
#include <stdlib.h>
#include "string.h"

const char *c_str(const string_t *this)
{
    return (!this ? NULL : this->str);
}
