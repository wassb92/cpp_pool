/*
** EPITECH PROJECT, 2022
** c++pool
** File description:
** Borg
*/

#ifndef BORG_HPP
#define BORG_HPP

#include "WarpSystem.hpp"
#include "Destination.hpp"

namespace Borg {
class Ship {
public:
    Ship();
    ~Ship();
    void setupCore(WarpSystem::Core *_core);
    void checkCore(void);
    WarpSystem::Core *core;
    Destination _home { UNICOMPLEX };
    Destination _location { _home };
    bool move(int warp, Destination d);
    bool move(int warp);
    bool move(Destination d);
    bool move();

private:
    int _side { 300 };
    short _maxWarp { 9 };
};
class Core {
public:
    Core();
    ~Core();
    bool _stability { true };
};
};

#endif /* !BORG_HPP */
