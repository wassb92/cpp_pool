/*
** EPITECH PROJECT, 2022
** ex03
** File description:
** day01
*/

#include <stdlib.h>
#include <stdio.h>

void array_1d_to_2d(const int *array, size_t height, size_t width, int ***res)
{
    int k = 0;
    *res = malloc(sizeof(int *) * (height + 1));

    if (!*res)
        return;
    for (size_t i = 0; i <= height; ++i) {
        (*res)[i] = malloc(sizeof(int) * (width + 1));
        if (!(*res)[i])
            return;
    }
    for (size_t i = 0; i < height; ++i)
        for (size_t t = 0; t < width; ++t, ++k)
            (*res)[i][t] = array[k];
}

void array_2d_free(int **array, size_t height, size_t width)
{
    (void)width;
    for (unsigned int i = 0; i <= height; ++i)
        free(array[i]);
    free(array);
}
