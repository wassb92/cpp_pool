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

unsigned int stack_get_size(stack_t stack)
{
    return list_get_size(stack);
}

bool stack_is_empty(stack_t stack)
{
    return list_is_empty(stack);
}

void stack_clear(stack_t *stack_ptr)
{
    return list_clear(stack_ptr);
}

void *stack_top(stack_t stack)
{
    if (!stack)
        return NULL;
    return stack->value;
}
