/*
** EPITECH PROJECT, 2022
** new
** File description:
** rush 2
*/

#include "new.h"
#include "player.h"

Object *new (const Class *class, ...)
{
    va_list ap;
    Object *obj = NULL;

    va_start(ap, class);
    obj = va_new(class, &ap);
    va_end(ap);
    return obj;
}

Object *va_new(const Class *class, va_list *ap)
{
    Object *obj = NULL;

    if (!class)
        raise("Class failed\n");
    obj = malloc(class->__size__);
    if (!obj)
        raise("Malloc failed\n");
    if (!memcpy(obj, class, class->__size__))
        raise("Memcpy failed\n");
    if (class->__ctor__)
        class->__ctor__(obj, ap);
    return obj;
}

void delete (Object *ptr)
{
    Class *class = ptr;

    if (class && class->__dtor__)
        class->__dtor__(ptr);
    free(ptr);
}