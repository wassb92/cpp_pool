/*
** EPITECH PROJECT, 2022
** rush
** File description:
** rush
*/

#include <stdio.h>
#include "new.h"
#include "int.h"

typedef struct
{
    Class base;
    int i;
} IntClass;

static void Int_ctor(IntClass *this, va_list *args)
{
    this->i = va_arg(*args, int);
}

static void Int_dtor(IntClass *this)
{
    (void)this;
    return;
}

static char *Int_to_string(IntClass *this)
{
    char *str;
    int len = 0;

    if (!this)
        raise("Empty Class");
    len = snprintf(NULL, 0, "<Int (%d)>", this->i);
    str = malloc(len + 1);
    if (!str)
        raise("failed malloc");
    snprintf(str, len + 1, "<Int (%d)>", this->i);
    return (str);
}

static Object *Int_add(const Object *this, const Object *other)
{
    IntClass *one = (IntClass *)this;
    IntClass *two = (IntClass *)other;

    return (new(Int, one->i + two->i));
}

static Object *Int_sub(const Object *this, const Object *other)
{
    IntClass *one = (IntClass *)this;
    IntClass *two = (IntClass *)other;

    return (new(Int, one->i - two->i));
}

static Object *Int_mul(const Object *this, const Object *other)
{
    IntClass *one = (IntClass *)this;
    IntClass *two = (IntClass *)other;

    return (new(Int, one->i * two->i));
}

static Object *Int_div(const Object *this, const Object *other)
{
    IntClass *one = (IntClass *)this;
    IntClass *two = (IntClass *)other;

    if (two->i == 0)
        raise("error divide with 0");
    return (new(Int, one->i / two->i));
}

static bool Int_eq(const Object *this, const Object *other)
{
    IntClass *one = (IntClass *)this;
    IntClass *two = (IntClass *)other;

    return (one->i == two->i);
}

static bool Int_lt(const Object *this, const Object *other)
{
    IntClass *one = (IntClass *)this;
    IntClass *two = (IntClass *)other;

    return (one->i < two->i);
}

static bool Int_gt(const Object *this, const Object *other)
{
    IntClass *one = (IntClass *)this;
    IntClass *two = (IntClass *)other;

    return (one->i > two->i);
}

static const IntClass _description = {
    {
        .__size__ = sizeof(IntClass),
        .__name__ = "Int",
        .__ctor__ = (ctor_t)&Int_ctor,
        .__dtor__ = (dtor_t)&Int_dtor,
        .__str__ = (to_string_t)&Int_to_string,
        .__add__ = (binary_operator_t)&Int_add,
        .__sub__ = (binary_operator_t)&Int_sub,
        .__mul__ = (binary_operator_t)&Int_mul,
        .__div__ = (binary_operator_t)&Int_div,
        .__eq__ = (binary_comparator_t)&Int_eq,
        .__lt__ = (binary_comparator_t)&Int_lt,
        .__gt__ = (binary_comparator_t)&Int_gt
    },
    .i = 0
};

const Class *Int = (const Class *)&_description;
