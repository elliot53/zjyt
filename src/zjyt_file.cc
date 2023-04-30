#include "file/zjyt_file.h"

namespace zjyt {

void Write(std::string file, std::string in)
{
    std::fstream f;
    int result{-1};
    if (file.empty())
    {
        result = mkdir(default_file.c_str(), S_IRWXU | S_IRWXG | S_IROTH | S_IXOTH);
        file = default_file + "zjyt.log";
    }
    f.open(file, std::ios::app | std::ios::in);
    f << time(nullptr) << " : " << in << std::endl;
    f.close();
}

bool zjyt_open(std::string file)
{
    if (access(file.c_str(), F_OK) != 0)
        return false;
    else 
        return true;
}

bool zjyt_append(std::string file, std::string in)
{
    
}

}  // namespace zjyt 