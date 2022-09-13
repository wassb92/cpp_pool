/*
** EPITECH PROJECT, 2022
** day 05
** File description:
** split
*/

#include <string.h>
#include <stdlib.h>
#include "string.h"

string_t **split_s(const string_t *this, char separator)
{
    return (string_t **)split_c(this, separator);
}

char **split_c(const string_t *this, char separator)
{
    char **buffer = NULL;
    int args = 1;
    int d = 0;
    int k = 0;

    if (!this || !this->str || this->str[0] == '\0')
        return NULL;
    for (unsigned int i = 0; this->str[i] != '\0'; ++i)
        this->str[i] == separator ? ++args : 0;
    buffer = malloc(sizeof(char *) * (args + 1));
    if (!buffer)
        return NULL;
    for (unsigned int a = 0; a < args; ++a, ++d) {
        buffer[a] = malloc(sizeof(char) * (strlen(this->str) + 1));
        for (k = 0; this->str[d] != separator && this->str[d] != '\0'; ++d)
            buffer[a][k++] = this->str[d];
        buffer[a][k] = '\0';
    }
    buffer[args] = NULL;
    return buffer;
}
