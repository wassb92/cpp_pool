/*
** EPITECH PROJECT, 2018
** rush
** File description:
** rush
*/

#include <stdio.h>
#include "new.h"
#include "float.h"

typedef struct
{
    Class base;
    float f;
} FloatClass;

static void Float_ctor(FloatClass *this, va_list *args)
{
    this->f = va_arg(*args, double);
}

static void Float_dtor(FloatClass *this)
{
    (void)this;
    return;
}

static char *Float_to_string(FloatClass *this)
{
    char *str;
    int len = 0;

    if (!this)
        raise("Empty Class");
    len = snprintf(NULL, 0, "<Float (%d)>", this->f);
    if (!len)
        raise("snprintf failed");
    str = malloc(len + 1);
    if (!str)
        raise("malloc failed");
    snprintf(str, len + 1, "<Float (%f)>", this->f);
    return (str);
}

static Object *Float_add(const Object *this, const Object *other)
{
    FloatClass *one = (FloatClass *)this;
    FloatClass *two = (FloatClass *)other;

    return (new(Float, one->f + two->f));
}

static Object *Float_sub(const Object *this, const Object *other)
{
    FloatClass *one = (FloatClass *)this;
    FloatClass *two = (FloatClass *)other;

    return (new(Float, one->f - two->f));
}

static Object *Float_mul(const Object *this, const Object *other)
{
    FloatClass *one = (FloatClass *)this;
    FloatClass *two = (FloatClass *)other;

    return (new(Float, one->f * two->f));
}

static Object *Float_div(const Object *this, const Object *other)
{
    FloatClass *one = (FloatClass *)this;
    FloatClass *two = (FloatClass *)other;

    if (two->f == 0)
        raise("Can't divide with 0");
    return (new(Float, one->f / two->f));
}

static bool Float_eq(const Object *this, const Object *other)
{
    FloatClass *one = (FloatClass *)this;
    FloatClass *two = (FloatClass *)other;

    return (one->f == two->f);
}

static bool Float_lt(const Object *this, const Object *other)
{
    FloatClass *one = (FloatClass *)this;
    FloatClass *two = (FloatClass *)other;

    return (one->f < two->f);
}

static bool Float_gt(const Object *this, const Object *other)
{
    FloatClass *one = (FloatClass *)this;
    FloatClass *two = (FloatClass *)other;

    return (one->f > two->f);
}

static const FloatClass _description = {
    {
        .__size__ = sizeof(FloatClass),
        .__name__ = "Float",
        .__ctor__ = (ctor_t)&Float_ctor,
        .__dtor__ = (dtor_t)&Float_dtor,
        .__str__ = (to_string_t)&Float_to_string,
        .__add__ = (binary_operator_t)&Float_add,
        .__sub__ = (binary_operator_t)&Float_sub,
        .__mul__ = (binary_operator_t)&Float_mul,
        .__div__ = (binary_operator_t)&Float_div,
        .__eq__ = (binary_comparator_t)&Float_eq,
        .__lt__ = (binary_comparator_t)&Float_lt,
        .__gt__ = (binary_comparator_t)&Float_gt
    },
    .f = 0.0
};

const Class *Float = (const Class *)&_description;
