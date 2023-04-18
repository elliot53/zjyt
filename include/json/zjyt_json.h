/**
 * @file json.h
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2023-04-03
 * 
 * @copyright Copyright (c) 2023
 * 
 */
#pragma once 
#ifndef JSON_H
#define JSON_H

#include "base/zjyt_base.h"
#include "jsoncpp/json.h"

namespace zjyt {
    
/**
 * @brief 
 * 
 * @param json_key 
 * @param json_value 
 * @param output_json 
 */
void StringToJson(const char *json_key, const char *json_value, std::string &output_json);

/**
 * @brief 
 * 
 * @param object_key 
 * @param object_value 
 * @param json_key 
 */
void ObjectToJson(std::string object_key, std::vector<double> object_value, const char *json_key, std::string &output_json);

/**
 * @brief 
 * 
 * @param json_key 
 * @param json_value 
 * @param output_json 
 */
void NumberToJson(const char *json_key, int json_value, std::string &output_json);

/**
 * @brief 
 * 
 * @param json_key 
 * @param json_value 
 * @param output_json 
 */
void NumberToJson(const char *json_key, double json_value, std::string &output_json);

/**
 * @brief 
 * 
 * @param json_key 
 * @param array 
 * @param array_size 
 * @param output_json 
 */
void ArrayToJson(const char *json_key, double *array, int array_size, std::string &output_json);

/**
 * @brief 
 * 
 * @param json_key 
 * @param array 
 * @param array_size 
 * @param output_json 
 */
void ArrayToJson(const char *json_key, int *array, int array_size, std::string &output_json);

/**
 * @brief 
 * 
 * @param multi_string 
 * @param output_json 
 */
void MultiStringToJson(std::map<std::string, std::string> multi_string, std::string root_key, std::string &output_json);

/**
 * @brief 
 * 
 * @param multi_string 
 * @param root_key 
 * @param output_json 
 */
void MultiArrayToJson(std::map<std::string, std::vector<int>> multi_array, std::string root_key, std::string &output_json);

/**
 * @brief 
 * 
 * @param multi_array 
 * @param multi_string 
 * @param root_key 
 * @param output_json 
 */
void MultiStringAndArrayToJson(std::map<std::string, std::vector<int>> multi_array, std::map<std::string, std::string> multi_string, std::string root_key, std::string &output_json);
/**
 * @brief 
 * 
 * @param drag_points 
 * @param root_key 
 * @param output_json 
 */
void DragPointsToJson(std::vector<std::pair<std::string, std::array<int, 6>>> drag_points, std::string root_key, std::string &output_json);

/*-------------------------------------------------------------------------------------------------------------*/

/**
 * @brief Get the Value From Json object
 * 
 * @param json_string 
 * @param output_value 
 * @return true 
 * @return false 
 */
bool GetValueFromJson(std::string json_string, std::string &output_value);
/**
 * @brief Get the Value From Json object
 * 
 * @param json_string 
 * @param output_value 
 * @return true 
 * @return false 
 */
bool GetValueFromJson(std::string json_string, std::vector<std::string> &output_value);
/**
 * @brief Get the Value From Json object
 * 
 * @param json_string 
 * @param output_value 
 * @return true 
 * @return false 
 */
bool GetValueFromJson(std::string json_string, std::map<std::string, std::string> &output_value);
/**
 * @brief Get the Value From Json object
 * 
 * @param json_string 
 * @param output_value 
 * @return true 
 * @return false 
 */
bool GetValueFromJson(std::string json_string, bool &output_value);
/**
 * @brief Get the Value From Json object
 * 
 * @param json_string 
 * @param output_value 
 * @return true 
 * @return false 
 */
bool GetValueFromJson(std::string json_string, int &output_value);

bool GetValueFromJson(std::string json_string, std::map<std::string, std::string> &output_value_str, std::map<std::string, std::array<double, 6>> &output_value_num);
/**
 * @brief Get the Array From Json object
 * 
 * @param json_string 
 * @param output_value 
 * @return true 
 * @return false 
 */
bool GetArrayFromJson(std::string json_string, std::vector<double> &output_value);
/**
 * @brief Get the Array From Json object
 * 
 * @param json_string 
 * @param output_value 
 * @return true 
 * @return false 
 */
bool GetArrayFromJson(std::string json_string, std::vector<int> &output_value);
/**
 * @brief Get the Program Commands From Json object
 * 
 * @param json_string 
 * @param output_value 
 * @return true 
 * @return false 
 */
bool GetProgramCommandsFromJson(std::string json_string, std::vector<std::pair<std::string, std::vector<double>>> &output_value);

}  // namespace zjyt 

#endif  // JSON_H