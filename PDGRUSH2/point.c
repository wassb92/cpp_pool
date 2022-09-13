/*
** EPITECH PROJECT, 2022
** Paradigms Seminar
** File description:
** Exercice 02
*/

#include <stdio.h>
#include "new.h"
#include "point.h"

typedef struct
{
    Class base;
    int x, y;
} PointClass;

static void Point_ctor(PointClass *this, va_list *args)
{
    if (args == NULL) {
        this->x = 0;
        this->y = 0;
    } else {
        this->x = va_arg(*args, int);
        this->y = va_arg(*args, int);
    }
}

static void Point_dtor(PointClass *this)
{
    (void)this;
    return;
}

to_string_t *Point_str(PointClass *this)
{
    int len = snprintf(NULL, 0, "<Point (%d, %d)>", this->x, this->y);
    char *str = malloc(len + 1);

    if (!str)
        raise("Malloc failed\n");
    sprintf(str, "<Point (%d, %d)>", this->x, this->y);
    return (to_string_t *)str;
}

static Object *Point_add(const Object *this, const Object *other)
{
    PointClass *c1 = (PointClass *)this;
    PointClass *c2 = (PointClass *)other;

    return (new (Point, c1->x + c2->x, c1->y + c2->y));
}

static Object *Point_sub(const Object *this, const Object *other)
{
    PointClass *c1 = (PointClass *)this;
    PointClass *c2 = (PointClass *)other;

    return (new (Point, c1->x - c2->x, c1->y - c2->y));
}

static const PointClass _description = {
    {
        .__size__ = sizeof(PointClass),
        .__name__ = "Point",
        .__ctor__ = (ctor_t)&Point_ctor,
        .__dtor__ = (dtor_t)&Point_dtor,
        .__str__ = (to_string_t)&Point_str,
        .__add__ = (binary_operator_t)&Point_add,
        .__sub__ = (binary_operator_t)&Point_sub,
        .__mul__ = NULL,
        .__div__ = NULL,
        .__eq__ = NULL,
        .__gt__ = NULL,
        .__lt__ = NULL },
    .x = 0,
    .y = 0
};

const Class *Point = (const Class *)&_description;
