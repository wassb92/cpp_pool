/*
** EPITECH PROJECT, 2022
** c++pool
** File description:
** Federation
*/

#ifndef FEDERATION_HPP
#define FEDERATION_HPP

#include <iostream>
#include "WarpSystem.hpp"
#include "Borg.hpp"
#include "Destination.hpp"

namespace Federation {
namespace Starfleet {
    class Captain {
    public:
        Captain(std::string name);
        ~Captain();
        std::string _name;
        int _age;
        std::string getName();
        int getAge();
        void setAge(int age);

    private:
    };
    class Ship {
    public:
        Ship(int length, int width, std::string name, short maxWarp);
        ~Ship();
        void setupCore(WarpSystem::Core *_core);
        void checkCore(void);
        WarpSystem::Core *core;
        WarpSystem::QuantumReactor *Quantum;
        Federation::Starfleet::Captain *captain;
        void promote(Federation::Starfleet::Captain *captain);
        Destination _home { EARTH };
        Destination _location { _home };
        bool move(int warp, Destination d);
        bool move(int warp);
        bool move(Destination d);
        bool move();

    protected:
    private:
        int _length;
        int _width;
        std::string _name;
        short _maxWarp;
    };

    class Ensign {
    public:
        Ensign(std::string name);
        ~Ensign();
        std::string _name;

    private:
    };
};
class Ship {
public:
    Ship(int length, int width, std::string name);
    ~Ship();
    void setupCore(WarpSystem::Core *_core);
    void checkCore(void);
    WarpSystem::Core *core;
    WarpSystem::QuantumReactor *Quantum;
    Destination _home { VULCAN };
    Destination _location { _home };
    bool move(int warp, Destination d);
    bool move(int warp);
    bool move(Destination d);
    bool move();

protected:
private:
    int _length;
    int _width;
    std::string _name;
    short _maxWarp { 0 };
};

}

#endif /* !FEDERATION_HPP */
