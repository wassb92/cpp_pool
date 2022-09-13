/*
** EPITECH PROJECT, 2022
** day 05
** File description:
** string
*/

#include <stdlib.h>
#include <string.h>
#include "string.h"

static void string_init_two(string_t *this, const char *s)
{
    this->split_s = split_s;
    this->split_c = split_c;
    this->print = print;
    this->join_c = join_c;
    this->join_s = join_s;
}

void string_init(string_t *this, const char *s)
{
    this->str = strdup(s);
    this->assign_s = assign_s;
    this->assign_c = assign_c;
    this->append_s = append_s;
    this->append_c = append_c;
    this->at = at;
    this->clear = clear;
    this->length = length;
    this->compare_s = compare_s;
    this->compare_c = compare_c;
    this->copy = copy;
    this->c_str = c_str;
    this->empty = empty;
    this->find_c = find_c;
    this->find_s = find_s;
    this->insert_c = insert_c;
    this->insert_s = insert_s;
    this->to_int = to_int;
    string_init_two(this, s);
}

void string_destroy(string_t *this)
{
    free(this->str);
    this->str = NULL;
}