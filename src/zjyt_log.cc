#include "log/zjyt_log.h"

namespace zjyt {

Log::Log(std::string log_file)
{
    m_log_file = log_file;
}

Log::~Log()
{
    m_log_handler.close();
}

void Log::set_log(std::string log_file)
{
    assert(!log_file.empty());
    m_log_file = log_file;
}

std::string Log::get_log() const
{
    return m_log_file;
}

bool Log::open()
{
    m_log_handler.open(m_log_file, std::ios::out | std::ios::app);
    if (!m_log_handler)
    {
        return false;
    }

    return true;
}

bool Log::close()
{
    m_log_handler.close();
}

void Log::log_msg(std::string msg)
{
    if (m_log_handler.is_open())
    {
        write_msg(msg);
    }
}

void Log::write_msg(std::string msg)
{
    m_log_handler << ">>> " << m_cnt
                  << " "  << msg 
                  << std::endl;
}


}  // namespace zjyt