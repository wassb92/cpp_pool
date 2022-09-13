/*
** EPITECH PROJECT, 2022
** day01 pm
** File description:
** ex00
*/

#include <stdio.h>
#include <stdlib.h>
#include "list.h"

void *list_get_elem_at_front(list_t list)
{
    return (list == NULL) ? 0 : list->value;
}

void *list_get_elem_at_back(list_t list)
{
    if (!list)
        return NULL;

    while (list->next)
        list = list->next;

    return (list->value);
}

void *list_get_elem_at_position(list_t list, unsigned int position)
{
    if (list == NULL || position >= list_get_size(list))
        return NULL;
    if (position == 0)
        return list_get_elem_at_front(list);
    for (unsigned int i = 0; i < position; ++i)
        list = list->next;
    return list->value;
}
