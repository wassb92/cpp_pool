/*
** EPITECH PROJECT, 2022
** ex02
** File description:
** day01
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "concat.h"

void concat_strings(const char *str1, const char *str2, char **res)
{
    static int i = 0;
    *res = malloc(sizeof(char) * (strlen(str1) + strlen(str2) + 1));

    if (!res)
        return;

    for (int t = 0; str1[t] != '\0'; ++t, ++i)
        (*res)[i] = str1[t];

    for (int t = 0; str2[t] != '\0'; ++t, ++i)
        (*res)[i] = str2[t];

    (*res)[i] = '\0';
}

void concat_struct(concat_t *str)
{
    static int i = 0;
    str->res = malloc(strlen(str->str1) + strlen(str->str2) + 1);

    if (!str->res)
        return;

    for (int t = 0; str->str1[t] != '\0'; ++t, ++i)
        str->res[i] = str->str1[t];

    for (int t = 0; str->str2[t] != '\0'; ++t, ++i)
        str->res[i] = str->str2[t];

    str->res[i] = '\0';
}
