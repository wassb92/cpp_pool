/*
** EPITECH PROJECT, 2022
** ex04
** File description:
** day01
*/

#include <stdio.h>
#include <string.h>
#include "print.h"

void print_normal(const char *str)
{
    printf("%s\n", str);
}

void print_reverse(const char *str)
{
    for (int i = strlen(str) - 1; i >= 0; --i)
        printf("%c", str[i]);
    printf("\n");
}

void print_upper(const char *str)
{
    for (unsigned int i = 0; str[i] != '\0'; ++i)
        printf("%c", (str[i] >= 'a' && str[i] <= 'z' ? str[i] - 32 : str[i]));
    printf("\n");
}

void print_42(const char *str)
{
    (void)str;
    printf("42\n");
}

void do_action(action_t action, const char *str)
{
    void (*ptr[PRINT_COUNT])(const char *) = {
        print_normal,
        print_reverse,
        print_upper,
        print_42,
    };
    ptr[action](str);
}
