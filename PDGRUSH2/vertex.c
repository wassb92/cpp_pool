/*
** EPITECH PROJECT, 2022
** Paradigms Seminar
** File description:
** Exercice 02
*/

#include <stdio.h>
#include "new.h"
#include "vertex.h"

typedef struct
{
    Class base;
    int x, y, z;
} VertexClass;

static void Vertex_ctor(VertexClass *this, va_list *args)
{
    if (args == NULL) {
        this->x = 0;
        this->y = 0;
        this->z = 0;
    } else {
        this->x = va_arg(*args, int);
        this->y = va_arg(*args, int);
        this->z = va_arg(*args, int);
    }
}

static void Vertex_dtor(VertexClass *this)
{
    (void)this;
    return;
}

to_string_t *Vertex_str(VertexClass *this)
{
    int len = snprintf(NULL, 0, "<Vertex (%d, %d, %d)>",
        this->x, this->y, this->z);
    char *str = malloc(len + 1);

    if (!str)
        raise("Malloc failed !\n");
    sprintf(str, "<Vertex (%d, %d, %d)>", this->x, this->y, this->z);
    return (to_string_t *)str;
}

static Object *Vertex_add(const Object *this, const Object *other)
{
    VertexClass *c1 = (VertexClass *)this;
    VertexClass *c2 = (VertexClass *)other;

    return (new (Vertex, c1->x + c2->x, c1->y + c2->y, c1->z + c2->z));
}

static Object *Vertex_sub(const Object *this, const Object *other)
{
    VertexClass *c1 = (VertexClass *)this;
    VertexClass *c2 = (VertexClass *)other;

    return (new (Vertex, c1->x - c2->x, c1->y - c2->y, c1->z - c2->z));
}

static const VertexClass _description = {
    { /* Class struct */
        .__size__ = sizeof(VertexClass),
        .__name__ = "Vertex",
        .__ctor__ = (ctor_t)&Vertex_ctor,
        .__dtor__ = (dtor_t)&Vertex_dtor,
        .__str__ = (to_string_t)&Vertex_str,
        .__add__ = (binary_operator_t)&Vertex_add,
        .__sub__ = (binary_operator_t)&Vertex_sub,
        .__mul__ = NULL,
        .__div__ = NULL,
        .__eq__ = NULL,
        .__gt__ = NULL,
        .__lt__ = NULL },
    .x = 0,
    .y = 0,
    .z = 0
};

const Class *Vertex = (const Class *)&_description;
