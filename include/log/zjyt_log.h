/**
 * @file zjyt_log.h
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2023-04-19
 * 
 * @copyright Copyright (c) 2023
 * 
 */
#pragma once 
#ifndef ZJYT_LOG_H
#define ZJYT_LOG_H

#include "base/zjyt_base.h"

namespace zjyt {

class Log
{

public:
    void set_log(std::string log_file);
    std::string get_log() const ;
    bool open();
    bool close();
    void log_msg(std::string msg);

private:
    void write_msg(std::string msg);

public:
    Log() = default;
    Log(std::string log_file);
    virtual ~Log();

private:
    long long m_cnt {0};
    std::ofstream m_log_handler {};
    std::string m_log_file {"/tmp/zjyt.log"};
};

}  // namespace zjyt

#endif // ZJYT_LOG_H