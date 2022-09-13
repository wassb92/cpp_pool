#include <iostream>
#include <stdexcept>
#include "Errors.hpp"
#include "CommunicationDevice.hpp"

CommunicationDevice::CommunicationDevice(std::istream &input,
    std::ostream &output)
try : _api(input, output) {

} catch (std::exception const &e) {
    throw CommunicationError(std::string("Error: ") + e.what());
}

CommunicationDevice::~CommunicationDevice()
{
}

void CommunicationDevice::startMission(std::string const &missionName, std::string *users, size_t nbUsers)
{
    try {
        for (size_t i = 0; i < nbUsers; ++i)
            _api.addUser(users[i]);
        _api.startMission(missionName);
    } catch (std::logic_error const &e) {
        throw(std::string("LogicError: ") + e.what());
    } catch (std::runtime_error const &e) {
        throw(std::string("RuntimeError: ") + e.what());
    } catch (std::exception const &e) {
        throw(std::string("Error: ") + e.what());
    }
}

void CommunicationDevice::send(std::string const &user, std::string const &message) const
{
    try {
        _api.sendMessage(user, message);
    } catch (const CommunicationError &e) {
        std::cerr << e.what() << std::endl;
    }
}

void CommunicationDevice::receive(std::string const &user, std::string &message) const
{
    try {
        _api.receiveMessage(user, message);
    } catch (const CommunicationError &e) {
        std::cerr << "INVALID MESSAGE" << std::endl;
    }
}
