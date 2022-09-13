/*
** EPITECH PROJECT, 2022
** rush3
** File description:
** rush3
*/

#include "const.hpp"
#include "MonitorCore.hpp"

std::vector<std::string> getFileContent(std::string const &file)
{
    std::ifstream m_file(file, std::ios::in);
    std::vector<std::string> data;
    std::string line;

    if (!m_file.is_open()) {
        std::cerr << "Cannot read file" << std::endl;
        EXIT_ERROR;
    }
    while (!m_file.eof()) {
        getline(m_file, line);
        if (m_file.fail())
            break;
        data.push_back(line);
    }
    m_file.close();
    return data;
}

std::vector<std::string> stringToVec(const std::string &str, const std::string &pattern)
{
    std::vector<std::string> res;
    if (str == "")
        return res;
    std::string strs = str + pattern;
    size_t pos = strs.find(pattern);
    while (pos != strs.npos) {
        std::string temp = strs.substr(0, pos);
        if (temp != "")
            res.push_back(temp);
        strs = strs.substr(pos + 1, strs.size());
        pos = strs.find(pattern);
    }
    return res;
}

void MonitorCore::RefreshInfo()
{
    std::vector<std::string> statInfo = getFileContent("/proc/stat");
    std::vector<std::string> Cupinfo = stringToVec(statInfo[0], " ");
    m_User = atol(Cupinfo[1].c_str());
    m_Nice = atol(Cupinfo[2].c_str());
    m_System = atol(Cupinfo[3].c_str());
    m_Idle = atol(Cupinfo[4].c_str());
    m_Iowait = atol(Cupinfo[5].c_str());
    m_Irq = atol(Cupinfo[6].c_str());
    m_Softirq = atol(Cupinfo[7].c_str());
    m_nbCore = 0;
    for (size_t i = 0; i < statInfo.size(); ++i) {
        if (statInfo[i].find("procs_running") != std::string::npos) {
            std::vector<std::string> processVec = stringToVec(statInfo[i], " ");
            m_procsRunning = atol(processVec[1].c_str());
            break;
        }
    }
    for (size_t i = 1; i < statInfo.size(); ++i)
        if (statInfo[i].find("cpu") != std::string::npos)
            ++m_nbCore;
    std::vector<std::string> AllCpuInof = getFileContent("/proc/cpuinfo");
    for (size_t i = 0; i < AllCpuInof.size(); ++i) {
        if (AllCpuInof[i].find("model name") != std::string::npos) {
            std::vector<std::string> MyCpuModel = stringToVec(AllCpuInof[i], " ");
            m_Model = "";
            for (size_t i = 2; i < MyCpuModel.size(); ++i) {
                m_Model += MyCpuModel[i];
                m_Model += " ";
            }
            break;
        }
    }
    for (size_t i = 0; i < AllCpuInof.size(); ++i) {
        if (AllCpuInof[i].find("cpu MHz") != std::string::npos) {
            std::vector<std::string> MyHz = stringToVec(AllCpuInof[i], " ");
            m_GHz = atof(MyHz[2].c_str());
            break;
        }
    }
    m_Usage = (100 - (((m_Idle) * 100) /
    (m_User + m_Nice + m_System + m_Idle + m_Iowait + m_Irq + m_Softirq)));
}

void MonitorCore::drawModule(sf::RenderWindow &window, Text text)
{
    RefreshInfo();
    text.setInfoAndDisplay("Model:\n" + this->m_Model, 120, 160, 13, sf::Color::White, window);
    text.setInfoAndDisplay("Cores: " + std::to_string(this->m_nbCore), 120, 200, 13, sf::Color::White, window);
    text.setInfoAndDisplay("Usage: " + std::to_string(this->m_Usage), 120, 230, 13, sf::Color::White, window);
    text.setInfoAndDisplay("Proc Run: " + std::to_string(this->m_procsRunning), 120, 260, 13, sf::Color::White, window);
    text.setInfoAndDisplay("Proc GHz: " + std::to_string(this->m_GHz), 120, 290, 13, sf::Color::White, window);
}