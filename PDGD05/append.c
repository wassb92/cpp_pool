/*
** EPITECH PROJECT, 2022
** day 05
** File description:
** append
*/

#include <string.h>
#include <stdlib.h>
#include "string.h"

void append_s(string_t *this, const string_t *ap)
{
    char *tmp = strdup(this->str);
    strcpy(tmp, this->str);

    free(this->str);
    this->str = realloc(NULL, (strlen(tmp) + strlen(ap->str) + 1));
    strcpy(this->str, tmp);
    strcat(this->str, ap->str);
    free(tmp);
}

void append_c(string_t *this, const char *ap)
{
    char *tmp = strdup(this->str);
    strcpy(tmp, this->str);

    free(this->str);
    this->str = realloc(NULL, (strlen(tmp) + strlen(ap) + 1));
    strcpy(this->str, tmp);
    strcat(this->str, ap);
    free(tmp);
}