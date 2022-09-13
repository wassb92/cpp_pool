/*
** EPITECH PROJECT, 2022
** day01 pm
** File description:
** ex02
*/

#include <stdio.h>
#include <stdlib.h>
#include "list.h"
#include "stack.h"

bool stack_push(stack_t *stack_ptr, void *elem)
{
    return list_add_elem_at_front(stack_ptr, elem);
}

bool stack_pop(stack_t *stack_ptr)
{
    return list_del_elem_at_front(stack_ptr);
}
