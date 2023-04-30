/**
 * @file zjyt_file.h
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2023-04-18
 * 
 * @copyright Copyright (c) 2023
 * 
 */
#pragma once 
#ifndef ZJYT_FILE_H
#define ZJYT_FILE_H

#include <fstream>
#include "base/zjyt_base.h"

namespace zjyt {

static std::string default_file = "/tmp/zjyt/";

void Write(std::string file, std::string in);

bool zjyt_open(std::string file);

bool zjyt_append(std::string file, std::string in);

}  // namespace zjyt 

#endif  // ZJYT_FILE_H