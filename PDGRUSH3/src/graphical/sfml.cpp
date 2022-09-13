/*
** EPITECH PROJECT, 2022
** B-PDG-300-PAR-3-1-PDGRUSH3-
** File description:
** sfml
*/

#include <vector>
#include "const.hpp"
#include "toolbar.hpp"
#include "IMonitorDisplay.hpp"
#include "sfml.hpp"
#include "MyGKrellm.hpp"

void drawRect(Rect rect, sf::RenderWindow &window, BoolToDispMod disMod)
{
    if (disMod.CPU == true)
        rect.setPositionAndDisplay(100, 50, window);
    if (disMod.names == true)
        rect.setPositionAndDisplay(450, 50, window);
    if (disMod.OS == true)
        rect.setPositionAndDisplay(800, 50, window);
    if (disMod.dateTime == true)
        rect.setPositionAndDisplay(1150, 50, window);
    if (disMod.RAM == true)
        rect.setPositionAndDisplay(100, 350, window);
    if (disMod.network == true)
        rect.setPositionAndDisplay(450, 350, window);
    if (disMod.uptime == true)
        rect.setPositionAndDisplay(800, 350, window);
}

void drawText(Text text, sf::RenderWindow &window, BoolToDispMod disMod)
{
    if (disMod.CPU == true)
        text.setInfoAndDisplay("CPU", 240, 80, 30, sf::Color::Blue, window);
    if (disMod.names == true)
        text.setInfoAndDisplay("Host/User Name", 500, 80, 30, sf::Color::Blue, window);
    if (disMod.OS == true)
        text.setInfoAndDisplay("OS And Kernel", 860, 80, 30, sf::Color::Blue, window);
    if (disMod.dateTime == true)
        text.setInfoAndDisplay("Date And Time", 1200, 80, 30, sf::Color::Blue, window);
    if (disMod.RAM == true)
        text.setInfoAndDisplay("RAM", 240, 380, 30, sf::Color::Blue, window);
    if (disMod.network == true)
        text.setInfoAndDisplay("Network load", 500, 380, 30, sf::Color::Blue, window);
    if (disMod.uptime == true)
        text.setInfoAndDisplay("Uptime", 860, 380, 30, sf::Color::Blue, window);
    if (disMod.process == true)
        text.setInfoAndDisplay("Process", 1260, 380, 30, sf::Color::Blue, window);

    if (!disMod.CPU && !disMod.names && !disMod.OS && !disMod.dateTime && !disMod.RAM && !disMod.network)
        text.setInfoAndDisplay("MONITOR CORE", 590, 340, 50, sf::Color::Yellow, window);
}

void drawModuleInfo(DisplayModule displayMod, sf::RenderWindow &window, Text text, SystemInfo data, BoolToDispMod disMod)
{
    if (disMod.CPU == true)
        displayMod.drawAllModules(data.m_core, window, text);
    if (disMod.names == true)
        displayMod.drawAllModules(data.m_name, window, text);
    if (disMod.OS == true)
        displayMod.drawAllModules(data.m_os, window, text);
    if (disMod.dateTime == true)
        displayMod.drawAllModules(data.m_time, window, text);
    if (disMod.RAM == true)
        displayMod.drawAllModules(data.m_ram, window, text);
    if (disMod.network == true)
        displayMod.drawAllModules(data.m_net, window, text);
    if (disMod.uptime == true)
        displayMod.drawAllModules(data.m_uptime, window, text);
    if (disMod.process == true)
        displayMod.drawAllModules(data.m_pro, window, text);
}

int sfmlPage()
{
    Rect rect;
    Text text;
    DisplayModule displayMod;
    SystemInfo data;
    sf::RectangleShape toolbar_blue(sf::Vector2f(1500, 100));
    toolbar_blue.setPosition(50, 800);
    toolbar_blue.setFillColor(sf::Color::Blue);
    toolbar_blue.setOutlineThickness(3);
    toolbar_blue.setOutlineColor(sf::Color::White);
    sf::Font font;
    if (!font.loadFromFile("src/graphical/fonts/FiraCode.ttf"))
        EXIT_ERROR;
    std::vector<Toolbar> tools = ToolTab(font);
    BoolToDispMod disMod;

    sf::RenderWindow window(sf::VideoMode(1600, 900), "MyGKrellm", sf::Style::Titlebar | sf::Style::Close);
    window.setFramerateLimit(1);
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event))
            if (event.type == sf::Event::Closed)
                window.close();

        window.clear();
        window.draw(toolbar_blue);
        for (unsigned int i = 0; i < MAX_MODULE; ++i)
            draw_toolbar(window, tools[i]);
        disMod.toolbar_set_Display(window);
        drawRect(rect, window, disMod);
        drawText(text, window, disMod);
        drawModuleInfo(displayMod, window, text, data, disMod);
        window.display();
    }
    return EXIT_SUCCESS;
}