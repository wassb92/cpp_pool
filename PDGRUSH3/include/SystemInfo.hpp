/*
** EPITECH PROJECT, 2022
** rush3
** File description:
** rush3
*/

#ifndef SYSDATA_H
#define SYSDATA_H

#include "MonitorCore.hpp"
#include "MonitorRam.hpp"
#include "MonitorNet.hpp"
#include "MonitorProcess.hpp"
#include "Name.hpp"
#include "Time.hpp"
#include "OS.hpp"
#include "Uptime.hpp"

class SystemInfo
{
public:
    MonitorNet m_net;
    MonitorCore m_core;
    MonitorRam m_ram;
    MonitorProcess m_pro;
    Name m_name;
    Time m_time;
    OS m_os;
    Uptime m_uptime;
};

#endif /* !SYSDATA_H */
