/*
** EPITECH PROJECT, 2022
** B-PDG-300-PAR-3-1-PDGRUSH3- include
** File description:
** const
*/

#ifndef CONST_HPP
#define CONST_HPP

#include <cstddef>

#define EXIT_ERROR             \
    do {                       \
        exit(EXIT_ERROR_CODE); \
    } while (0)

[[maybe_unused]] static const char *EMPTY_STR = "EMPTY";
[[maybe_unused]] static const size_t EMPTY_INT = 0;
[[maybe_unused]] static const unsigned short EXIT_ERROR_CODE = 84;
[[maybe_unused]] static const char *TEXT_MODE = "text";
[[maybe_unused]] static const char *GRAPHICAL_MODE = "graphical";
[[maybe_unused]] static const unsigned short int MAX_MODULE = 8;

#endif /* !CONST_HPP */
