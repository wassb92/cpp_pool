#pragma once

#include <string>

class NasaError;
class MissionCriticalError;
class LifeCriticalError;
class UserError;
class CommunicationError;

class NasaError : public std::exception {
public:
    NasaError(std::string const &message,
        std::string const &component = "Unknown");
    const char *what() const throw();

    virtual std::string const &getComponent() const;

private:
    std::string _message;
    std::string _component;
};

class MissionCriticalError : public NasaError {
public:
    MissionCriticalError(std::string const &message,
        std::string const &component = "Unknown");
};

class LifeCriticalError : public NasaError {
public:
    LifeCriticalError(std::string const &message,
        std::string const &component = "Unknown");
};

class UserError : public NasaError {
public:
    UserError(std::string const &message,
        std::string const &component = "Unknown");
};

class CommunicationError : public NasaError {
public:
    CommunicationError(std::string const &message);
};