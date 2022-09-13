/*
** EPITECH PROJECT, 2022
** c++pool
** File description:
** WarpSystem
*/

#include "WarpSystem.hpp"

WarpSystem::Core::Core(QuantumReactor *_coreReactor)
{
    this->_coreReactor = _coreReactor;
}

WarpSystem::Core::~Core()
{
}

bool WarpSystem::QuantumReactor::isStable()
{
    return this->_stability;
}

void WarpSystem::QuantumReactor::setStability(bool stability)
{
    this->_stability = stability;
}

WarpSystem::QuantumReactor *WarpSystem::Core::checkReactor(void)
{
    return (this->_coreReactor);
}
