/*
** EPITECH PROJECT, 2022
** day01 pm
** File description:
** ex00
*/

#include <stdio.h>
#include <stdlib.h>
#include "int_list.h"

bool int_list_add_elem_at_front(int_list_t *front_ptr, int elem)
{
    int_list_t cell = malloc(sizeof(int_node_t));

    if (!cell)
        return false;

    cell->value = elem;
    cell->next = *front_ptr;
    *front_ptr = cell;
    return true;
}

bool int_list_add_elem_at_back(int_list_t *front_ptr, int elem)
{
    int_list_t tmp = *front_ptr;
    int_list_t cell = NULL;

    if (!*front_ptr)
        return int_list_add_elem_at_front(front_ptr, elem);
    cell = malloc(sizeof(int_node_t));
    cell->next = NULL;
    cell->value = elem;

    while (tmp->next)
        tmp = tmp->next;

    tmp->next = cell;

    return true;
}

bool int_list_add_elem_at_position(int_list_t *front_ptr, int elem,
    unsigned int position)
{
    int_list_t pre = *front_ptr;
    int_list_t current = *front_ptr;
    int_list_t cell = NULL;

    if (position == 0)
        return int_list_add_elem_at_front(front_ptr, elem);
    cell = malloc(sizeof(int_node_t));
    if (position > int_list_get_size(*front_ptr) || !cell) {
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