/*
** EPITECH PROJECT, 2022
** ex01
** File description:
** day01
*/

#include <stdio.h>

void mul_div_long(int a, int b, int *mul, int *div)
{
    *mul = a * b;
    *div = b == 0 ? 42 : a / b;
}

void mul_div_short(int *a, int *b)
{
    int tmp_a = *a;
    int tmp_b = *b;

    *a = tmp_a * tmp_b;
    *b = tmp_b == 0 ? 42 : tmp_a / tmp_b;
}
