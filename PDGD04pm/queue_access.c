/*
** EPITECH PROJECT, 2022
** day01 pm
** File description:
** ex03
*/

#include <stdio.h>
#include <stdlib.h>
#include "list.h"
#include "queue.h"

unsigned int queue_get_size(queue_t queue)
{
    return list_get_size(queue);
}

bool queue_is_empty(queue_t queue)
{
    return list_is_empty(queue);
}

void queue_clear(queue_t *queue_ptr)
{
    return list_clear(queue_ptr);
}

void *queue_front(queue_t queue)
{
    return list_get_elem_at_front(queue);
}
