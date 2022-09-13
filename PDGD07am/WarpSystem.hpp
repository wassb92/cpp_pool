/*
** EPITECH PROJECT, 2022
** c++pool
** File description:
** WarpSystem
*/

#ifndef WARPSYSTEM_HPP
#define WARPSYSTEM_HPP

#include <iostream>

namespace WarpSystem {
class QuantumReactor {
public:
    bool _stability { true };
    bool isStable(void);
    void setStability(bool stability);
};
class Core {
public:
    Core(QuantumReactor *_coreReactor);
    ~Core();
    QuantumReactor *_coreReactor;
    QuantumReactor *checkReactor(void);
};
};

#endif /* !WARPSYSTEM_HPP */
