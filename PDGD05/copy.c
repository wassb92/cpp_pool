/*
** EPITECH PROJECT, 2022
** day 05
** File description:
** copy
*/

#include <string.h>
#include <stdlib.h>
#include "string.h"

size_t copy(const string_t *this, char *s, size_t n, size_t pos)
{
    size_t index = 0;

    if (!this || !this->str || !s)
        return 0;

    for (unsigned int i = 0; i < strlen(this->str); ++i) {
        if (i != pos) {
            continue;
        }
        for (; (i < strlen(this->str)) && (index < n) && s; ++index, ++i)
            s[index] = this->str[i];
        s[index] = '\0';
        ++i;
    }
    return index;
}