/*
** EPITECH PROJECT, 2022
** c++pool B-PDG-300-PAR-3-1-PDGD10pm-
** File description:
** Errors
*/

#include "Errors.hpp"

NasaError::NasaError(std::string const &message, std::string const &component)
{
    this->_component = component;
    this->_message = message;
}

std::string const &NasaError::getComponent() const
{
    return this->_component;
}

CommunicationError::CommunicationError(std::string const &message)
    : NasaError(message, "CommunicationDevice")
{
}

MissionCriticalError::MissionCriticalError(std::string const &message, std::string const &component)
    : NasaError(message, component)
{
}

LifeCriticalError::LifeCriticalError(std::string const &message, std::string const &component)
    : NasaError(message, component)
{
}

UserError::UserError(std::string const &message, std::string const &component)
    : NasaError(message, component)
{
}

const char *NasaError::what() const throw()
{
    return _message.c_str();
}
