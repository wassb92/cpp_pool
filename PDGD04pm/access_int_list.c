/*
** EPITECH PROJECT, 2022
** day01 pm
** File description:
** ex00
*/

#include <stdio.h>
#include <stdlib.h>
#include "int_list.h"

int int_list_get_elem_at_front(int_list_t list)
{
    return (list == NULL) ? 0 : list->value;
}

int int_list_get_elem_at_back(int_list_t list)
{
    if (!list)
        return 0;

    while (list->next)
        list = list->next;

    return (list->value);
}

int int_list_get_elem_at_position(int_list_t list, unsigned int position)
{
    if (list == NULL || position >= int_list_get_size(list))
        return 0;
    if (position == 0)
        return int_list_get_elem_at_front(list);
    for (unsigned int i = 0; i < position; ++i)
        list = list->next;
    return list->value;
}