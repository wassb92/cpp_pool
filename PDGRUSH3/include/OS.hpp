/*
** EPITECH PROJECT, 2022
** include informations
** File description:
** OS
*/

#ifndef OS_HPP
#define OS_HPP

#include <string>
#include <sys/utsname.h>
#include "IMonitorModule.hpp"

class OS : virtual public IMonitorModule {
public:
    OS();
    ~OS();
    std::string getName() const;
    std::string getKernel() const;

    void drawModule(sf::RenderWindow &window, Text text);

private:
    utsname info;
};

#endif /* !OS_HPP */