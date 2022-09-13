/*
** EPITECH PROJECT, 2022
** day01 pm
** File description:
** ex00
*/

#include <stdio.h>
#include <stdlib.h>
#include "int_list.h"

unsigned int int_list_get_size(int_list_t list)
{
    unsigned int i = 0;

    if (!list)
        return 0;

    for (; list; ++i, list = list->next);

    return i;
}

bool int_list_is_empty(int_list_t list)
{
    return (list == NULL);
}

void int_list_dump(int_list_t list)
{
    while (list) {
        printf("%d\n", list->value);
        list = list->next;
    }
}
