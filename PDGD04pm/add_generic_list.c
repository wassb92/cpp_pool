/*
** EPITECH PROJECT, 2022
** day01 pm
** File description:
** ex00
*/

#include <stdio.h>
#include <stdlib.h>
#include "list.h"

bool list_add_elem_at_front(list_t *front_ptr, void *elem)
{
    list_t cell = malloc(sizeof(node_t));

    if (!cell)
        return false;

    cell->value = elem;
    cell->next = *front_ptr;
    *front_ptr = cell;
    return true;
}

bool list_add_elem_at_back(list_t *front_ptr, void *elem)
{
    list_t tmp = *front_ptr;
    list_t cell = NULL;

    if (!*front_ptr)
        return list_add_elem_at_front(front_ptr, elem);
    cell = malloc(sizeof(node_t));
    cell->next = NULL;
    cell->value = elem;

    while (tmp->next)
        tmp = tmp->next;

    tmp->next = cell;

    return true;
}

bool list_add_elem_at_position(list_t *front_ptr, void *elem,
    unsigned int position)
{
    list_t pre = *front_ptr;
    list_t current = *front_ptr;
    list_t cell = NULL;

    if (position == 0)
        return list_add_elem_at_front(front_ptr, elem);
    cell = malloc(sizeof(node_t));
    if (position > list_get_size(*front_ptr) || !cell) {
        free(cell);
        return false;
    }
    cell->value = elem;
    cell->next = NULL;
    for (unsigned int i = 0; i < position; ++i) {
        pre = current;
        current = current->next;
    }
    pre->next = cell;
    cell->next = current;
    return true;
}