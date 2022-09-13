/*
** EPITECH PROJECT, 2022
** day 05
** File description:
** insert
*/

#include <string.h>
#include <stdlib.h>
#include "string.h"

void insert_c(string_t *this, size_t pos, const char *str)
{
    char *new_str = malloc(this->length(this) + strlen(str) + 10);
    unsigned int i = 0;
    unsigned int t = 0;

    if (this->str)
        this->str = realloc(this->str, this->length(this) + strlen(str) + 10);
    else
        return free(new_str);
    if (pos >= this->length(this))
        return append_c(this, str);
    for (; t < pos; ++i, ++t)
        new_str[i] = this->str[t];
    for (unsigned int t = 0; str[t] != '\0'; ++i, ++t)
        new_str[i] = str[t];
    for (; this->str[t] != '\0'; ++i, ++t)
        new_str[i] = this->str[t];
    new_str[i] = '\0';
    strcpy(this->str, new_str);
    free(new_str);
}

void insert_s(string_t *this, size_t pos, const string_t *str)
{
    return insert_c(this, pos, str->str);
}
