/*
** EPITECH PROJECT, 2022
** day 05
** File description:
** join
*/

#include <string.h>
#include <stdlib.h>
#include "string.h"

void join_c(string_t *this, char delim, const char *const *array)
{
    array = (const char* const*)this->split_c(this, delim);
}

void join_s(string_t *this, char delim, const string_t *const *array)
{
    array = (const string_t* const*)this->split_s(this, delim);
}
