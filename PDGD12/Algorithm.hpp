/*
** EPITECH PROJECT, 2022
** c++pool B-PDG-300-PAR-3-1-PDGD12-
** File description:
** Algorithm
*/

#ifndef ALGORITHM_HPP
#define ALGORITHM_HPP

#include <iostream>

template <typename T>
void swap(T &a, T &b)
{
    std::swap(a, b);
}

template <typename T>
T min(const T a, const T b)
{
    return std::min(a, b);
}

template <typename T>
T max(const T a, const T b)
{
    return std::max(a, b);
}

template <typename T>
T clamp(const T value, const T min, const T max)
{
    return std::clamp(value, min, max);
}

#endif /* !ALGORITHM_HPP */
