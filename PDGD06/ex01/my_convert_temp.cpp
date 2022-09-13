/*
** EPITECH PROJECT, 2022
** my_convert_temp
** File description:
** my_convert_temp cpp project
*/

#include <iostream>
#include <fstream>
#include <bits/stdc++.h>
#include <string>

static float extract_float(std::string input)
{
    const std::string digits = "-+0123456789";
    float nb = 0.0;
    unsigned i = input.find_first_of(digits);

    if (i >= UINT_MAX - 1)
        return nb;
    if (i < std::string::npos)
        std::stringstream(input.substr(i)) >> nb;

    return nb;
}

static std::string extract_string(std::string input)
{
    std::string str;

    for (unsigned int i = 0; input[i] != '\0'; ++i)
        if (input[i] == ' ') {
            ++i;
            for (unsigned int t = 0; input[i] != ' ' && input[i] != '\0'; ++t, ++i)
                str.push_back(input[i]);
            return str;
        }
    return str;
}

int main(void)
{
    std::string input { NULL };
    std::string str { NULL };
    float nb = 0;

    std::getline(std::cin, input);
    str = extract_string(input);
    nb = extract_float(input);
    if (str == "Celsius") {
        nb = (nb / (5.0 / 9.0)) + 32;
        std::cout << std::setw(16) << std::fixed << std::setprecision(3)
                  << nb << std::setw(16) << "Fahrenheit" << std::endl;
        return 0;
    }
    if (str == "Fahrenheit") {
        nb = 5.0 / 9.0 * (nb - 32);
        std::cout << std::setw(16) << std::fixed << std::setprecision(3)
                  << nb << std::setw(16) << "Celsius" << std::endl;
        return 0;
    }
    return 0;
}