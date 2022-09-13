/*
** EPITECH PROJECT, 2022
** day01 pm
** File description:
** ex00
*/

#include <stdio.h>
#include <stdlib.h>
#include "list.h"

unsigned int list_get_size(list_t list)
{
    unsigned int i = 0;

    for (; list; ++i, list = list->next);

    return i;
}

bool list_is_empty(list_t list)
{
    return (list == NULL);
}

void list_dump(list_t list, value_displayer_t val_disp)
{
    while (list) {
        val_disp(list->value);
        list = list->next;
    }
}