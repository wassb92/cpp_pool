/*
** EPITECH PROJECT, 2022
** include informations
** File description:
** MonitorCore
*/

#ifndef MONITORCORE_HPP
#define MONITORCORE_HPP

#include <iostream>
#include <fstream>
#include <vector>
#include "IMonitorModule.hpp"

class MonitorCore : virtual public IMonitorModule
{
public:
	void RefreshInfo();
	std::string m_Model;
	float m_GHz;
	int m_nbCore;
	size_t m_procsRunning;
	int m_Usage;
	size_t m_User;
	size_t m_Nice;
	size_t m_System;
	size_t m_Idle;
	size_t m_Iowait;
	size_t m_Irq;
	size_t m_Softirq;
	// DRAW_MODULE

    void drawModule(sf::RenderWindow &window, Text text);
};

#endif /* !MONITORCORE_HPP */
