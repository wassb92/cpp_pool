/*
** EPITECH PROJECT, 2022
** day 05
** File description:
** print
*/

#include <string.h>
#include <unistd.h>
#include "string.h"

void print(const string_t *this)
{
    if (this->str)
        write(1, this->str, strlen(this->str));
}