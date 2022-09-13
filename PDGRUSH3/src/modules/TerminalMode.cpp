/*
** EPITECH PROJECT, 2022
** rush3
** File description:
** rush3
*/

#include "MyGKrellm.hpp"

void InitTerminal()
{
    initscr();
    start_color();
    noecho();
    keypad(stdscr, TRUE);
    timeout(1000);
    curs_set(FALSE);
    init_pair(1, COLOR_BLUE, COLOR_BLACK);
    init_pair(2, COLOR_RED, COLOR_BLACK);
    init_pair(3, COLOR_CYAN, COLOR_BLACK);
    init_pair(4, COLOR_MAGENTA, COLOR_BLACK);
    init_pair(5, COLOR_GREEN, COLOR_BLACK);
    init_pair(6, COLOR_WHITE, COLOR_BLACK);
}

void change_page(int key, int &page)
{
    if (key == KEY_LEFT) {
        --page;
        if (page < 0)
            page = 5;
    }
    if (key == KEY_RIGHT) {
        ++page;
        if (page > 5)
            page = 0;
    }
}

void printInfo(SystemInfo const &all_data, int const &page)
{
    if (page == 0)
    {
        attron(COLOR_PAIR(1));
        printw("\t\t\t<==================> OS information  <==================>\n");
        printw("\nUser Name  : %s\n", all_data.m_name.getUserName().c_str());
        printw("\nHost Name  : %s\n", all_data.m_name.getHostName().c_str());
        printw("\nKernel     : %s\n", all_data.m_os.getKernel().c_str());
        printw("\nSystem     : %s\n", all_data.m_os.getName().c_str());
        mvprintw(40, 0, "\t\t<=============> <-LEFT KEY || NEXT PAGE || RIGHT KEY ->  <=============>\n");
        attroff(COLOR_PAIR(1));
    }
    if (page == 1)
    {
        attron(COLOR_PAIR(2));
        printw("\t\t\t<==================> CPU information <==================>\n");
        printw("\nCPU Model     : %s\n", all_data.m_core.m_Model.c_str());
        printw("\nCPU Frequency : %.2f Mhz\n", all_data.m_core.m_GHz);
        printw("\nCPU Usage     : %d %\n", all_data.m_core.m_Usage);
        mvprintw(9, 25, "<[---------|---------|---------|---------|----------]>");
        for (int i = 0, j = 27; i < all_data.m_core.m_Usage / 2; i++, j++)
        {
            mvprintw(9, j, "o");
            mvprintw(10, j, " ");
        }
        printw("\n\nCPU Core Number     : %d\n", all_data.m_core.m_nbCore);
        printw("\nProcess running     : %d\n", all_data.m_core.m_procsRunning);
        printw("\nUser      : %d\n", all_data.m_core.m_User);
        printw("\nNice      : %d\n", all_data.m_core.m_Nice);
        printw("\nSystem    : %d\n", all_data.m_core.m_System);
        printw("\nIdle      : %d\n", all_data.m_core.m_Idle);
        printw("\nIOwait    : %d\n", all_data.m_core.m_Iowait);
        printw("\nIRQ       : %d\n", all_data.m_core.m_Irq);
        printw("\nSoftIRQ   : %d\n", all_data.m_core.m_Softirq);
        mvprintw(40, 0, "\t\t<=============> <-LEFT KEY || NEXT PAGE || RIGHT KEY ->  <=============>\n");
        attroff(COLOR_PAIR(2));
    }
    if (page == 2)
    {
        attron(COLOR_PAIR(3));
        printw("\t\t\t<==================> RAM information <===================>\n");
        printw("\nRAM Total      \t: %d kB\n", all_data.m_ram.m_memTotal);
        printw("\nRAM Used       \t: %d kB\n", all_data.m_ram.m_memUsed);
        printw("\nRAM Available  \t: %d kB\n", all_data.m_ram.m_memAvailable);
        printw("\nRAM Free       \t: %d kB\n", all_data.m_ram.m_memFree);
        printw("\nRAM Buffers    \t: %d kB\n", all_data.m_ram.m_memBuffers);
        printw("\nRAM Cached     \t: %d kB\n", all_data.m_ram.m_memCached);
        printw("\nRAM Usage      \t: %d %\n\n", all_data.m_ram.m_memUsage);
        mvprintw(16, 25, "<[---------|---------|---------|---------|----------]>");
        for (int i = 0, j = 27; i < all_data.m_ram.m_memUsage / 2; i++, j++)
        {
            mvprintw(16, j, "o");
        }
        mvprintw(40, 0, "\t\t<=============> <-LEFT KEY || NEXT PAGE || RIGHT KEY ->  <=============>\n");
        attroff(COLOR_PAIR(3));
    }
    if (page == 3) {
        attron(COLOR_PAIR(4));
        printw("\t\t\t<==================> NET information  <==================>\n");
        printw("\nNetwork Programs  : %d\n", all_data.m_net.numberProgram);
        printw("\nName And Infomation  : \n");
        for (int i = 0; i < all_data.m_net.program.size(); i++) {
            printw("%s     \n\tRecive Bytes : %d\n", all_data.m_net.program[i].name.c_str(), all_data.m_net.program[i].ReciveBt);
            printw("\tReceive Packets : %d\n", all_data.m_net.program[i].RecivePaket);
            printw("\tTransmit Bytes : %d\n", all_data.m_net.program[i].TransmitBt);
            printw("\tTransmit Packets : %d\n\n", all_data.m_net.program[i].TransmitPaket);
        }
        mvprintw(40, 0, "\t\t<=============> <-LEFT KEY || NEXT PAGE || RIGHT KEY ->  <=============>\n");
        attroff(COLOR_PAIR(4));
    }
    if (page == 4) {
        attron(COLOR_PAIR(5));
        printw("\t\t\t<==================> PROCESS information  <==================>\n");
        printw("\nProcess List  : \n\n");
        for (int i = 0; i < all_data.m_pro.programList.size(); i++)
            printw("\n%s\n", all_data.m_pro.programList[i].c_str());
        mvprintw(40, 0, "\t\t<=============> <-LEFT KEY || NEXT PAGE || RIGHT KEY ->  <=============>\n");
        attroff(COLOR_PAIR(5));
    }
    if (page == 5) {
        attron(COLOR_PAIR(6));
        printw("\t\t\t<==================> UPTIME information  <==================>\n");
        printw("\nLocal Time : %s\n", all_data.m_time.getTime().c_str());
        printw("\nComputer Running Time :\n");
        printw("\n\t\tDay    : %d\n", all_data.m_uptime.upTime->tm_mday);
        printw("\n\t\tHour   : %d\n", all_data.m_uptime.upTime->tm_hour);
        printw("\n\t\tMinute : %d\n", all_data.m_uptime.upTime->tm_min);
        printw("\n\t\tSecond : %d\n", all_data.m_uptime.upTime->tm_sec);
        mvprintw(40, 0, "\t\t<=============> <-LEFT KEY || NEXT PAGE || RIGHT KEY ->  <=============>\n");
        attroff(COLOR_PAIR(6));
    }
}
