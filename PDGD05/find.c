/*
** EPITECH PROJECT, 2022
** day 05
** File description:
** find
*/

#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "string.h"

int find_s(const string_t *this, const string_t *str, size_t pos)
{
    return find_c(this, this->str, pos);
}

int find_c(const string_t *this, const char *str, size_t pos)
{
    char *find = NULL;

    if (!str || strlen(str) < pos || this->length(this) <= pos)
        return -1;

    find = strstr(&this->str[pos], str);

    return ((find) ? (find - this->str) : -1);
}