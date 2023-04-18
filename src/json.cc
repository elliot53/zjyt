#include "json/zjyt_json.h"

namespace zjyt {
    
void StringToJson(const char *json_key, const char *json_value, std::string &output_json)
{
    Json::Value root;
    Json::StreamWriterBuilder builder;

    root[json_key] = json_value;
    output_json = Json::writeString(builder, root);
}

void ObjectToJson(std::string object_key, std::vector<double> object_value, const char *json_key, std::string &output_json)
{
    Json::Value root;
    Json::Value data;
    Json::StreamWriterBuilder builder;

    for (auto &i : object_value)
    {
        data[object_key].append(i);
    }
    root[json_key] = data;
    output_json = Json::writeString(builder, root);
}

void NumberToJson(const char *json_key, int json_value, std::string &output_json)
{
    Json::Value root;
    Json::StreamWriterBuilder builder;

    root[json_key] = json_value;
    output_json = Json::writeString(builder, root);
}

void NumberToJson(const char *json_key, double json_value, std::string &output_json)
{
    Json::Value root;
    Json::StreamWriterBuilder builder;

    root[json_key] = json_value;
    output_json = Json::writeString(builder, root);
}

void ArrayToJson(const char *json_key, double *array, int array_size, std::string &output_json)
{
    Json::Value root;
    Json::Value data;
    Json::StreamWriterBuilder builder;

    for (int i{0}; i < array_size; i++)
    {
        data[i] = array[i];
    }
    root[json_key] = data;
    output_json = Json::writeString(builder, root);
}

void ArrayToJson(const char *json_key, int *array, int array_size, std::string &output_json)
{
    Json::Value root;
    Json::Value data;
    Json::StreamWriterBuilder builder;

    for (int i{0}; i < array_size; i++)
    {
        data[i] = array[i];
    }
    root[json_key] = data;
    output_json = Json::writeString(builder, root);
}

void MultiStringToJson(std::map<std::string, std::string> multi_string, std::string root_key, std::string &output_json)
{
    Json::Value root;
    Json::Value data;
    Json::StreamWriterBuilder builder;

    for (auto &i : multi_string)
    {
        data[i.first] = i.second;
    }
    root[root_key] = data;
    output_json = Json::writeString(builder, root);
}

void MultiArrayToJson(std::map<std::string, std::vector<int>> multi_array, std::string root_key, std::string &output_json)
{
    Json::Value root;
    Json::Value data;
    Json::StreamWriterBuilder builder;

    for (auto &i : multi_array)
    {
        for (auto &j : i.second)
        {
            data[i.first].append(j);
        }
    }
    root[root_key] = data;
    output_json = Json::writeString(builder, root);
}

void MultiStringAndArrayToJson(std::map<std::string, std::vector<int>> multi_array, std::map<std::string, std::string> multi_string, std::string root_key, std::string &output_json)
{
    Json::Value root;
    Json::Value data;
    Json::StreamWriterBuilder builder;

    for (auto &i : multi_string)
    {
        data[i.first] = i.second;
    }
    for (auto &i : multi_array)
    {
        for (auto &j : i.second)
        {
            data[i.first].append(j);
        }
    }
    root[root_key] = data;
    output_json = Json::writeString(builder, root);
}

void DragPointsToJson(std::vector<std::pair<std::string, std::array<int, 6>>> drag_points, std::string root_key, std::string &output_json)
{
    Json::Value root;
    Json::Value data;
    Json::StreamWriterBuilder builder;

    for (auto &single_point : drag_points)
    {
        for (size_t index{0}; index < single_point.second.size(); index++)
        {
            data[single_point.first].append(single_point.second[index]);
        }
    }
    root[root_key] = data;
    output_json = Json::writeString(builder, root);
}

bool GetValueFromJson(std::string json_string, std::string &output_value)
{
    bool result{false};
    Json::Value root;
    Json::Value::Members keys;
    JSONCPP_STRING error;
    Json::CharReaderBuilder builder;
    const std::unique_ptr<Json::CharReader> reader(builder.newCharReader());

    result = reader->parse(json_string.c_str(), json_string.c_str() + json_string.size(), &root, &error);
    if (!result)
    {
        return result;
    }
    keys = root.getMemberNames();
    output_value = root[keys.front()].asString();
    return true;
}

bool GetValueFromJson(std::string json_string, std::vector<std::string> &output_value)
{
    bool result{false};
    Json::Value root;
    Json::Value::Members keys;
    JSONCPP_STRING error;
    Json::CharReaderBuilder builder;
    const std::unique_ptr<Json::CharReader> reader(builder.newCharReader());

    result = reader->parse(json_string.c_str(), json_string.c_str() + json_string.size(), &root, &error);
    if (!result)
    {
        return result;
    }
    keys = root.getMemberNames();
    for (auto &key : keys)
    {
        output_value.push_back(root[key].asString());
    }
    return true;
}
bool GetValueFromJson(std::string json_string, std::map<std::string, std::string> &output_value)
{
    bool result{false};
    Json::Value root;
    Json::Value::Members keys;
    JSONCPP_STRING error;
    Json::CharReaderBuilder builder;
    const std::unique_ptr<Json::CharReader> reader(builder.newCharReader());

    result = reader->parse(json_string.c_str(), json_string.c_str() + json_string.size(), &root, &error);
    if (!result)
    {
        return result;
    }
    keys = root.getMemberNames();
    for (auto &key : keys)
    {
        output_value[key] = root[key].asString();
    }
    return true;
}
bool GetValueFromJson(std::string json_string, bool &output_value)
{
    bool result{false};
    Json::Value root;
    Json::Value::Members keys;
    JSONCPP_STRING error;
    Json::CharReaderBuilder builder;
    const std::unique_ptr<Json::CharReader> reader(builder.newCharReader());

    result = reader->parse(json_string.c_str(), json_string.c_str() + json_string.size(), &root, &error);
    if (!result)
    {
        return result;
    }
    keys = root.getMemberNames();
    output_value = root[keys.front()].asBool();
    return true;
}

bool GetValueFromJson(std::string json_string, int &output_value)
{
    bool result{false};
    Json::Value root;
    Json::Value::Members keys;
    JSONCPP_STRING error;
    Json::CharReaderBuilder builder;
    const std::unique_ptr<Json::CharReader> reader(builder.newCharReader());

    result = reader->parse(json_string.c_str(), json_string.c_str() + json_string.size(), &root, &error);
    if (!result)
    {
        return result;
    }
    keys = root.getMemberNames();
    output_value = root[keys.front()].asInt();
    return true;
}

bool GetValueFromJson(std::string json_string, std::map<std::string, std::string> &output_value_str, std::map<std::string, std::array<double, 6>> &output_value_num)
{
    bool result{false};
    Json::Value root;
    std::string space{"space"};
    std::string point{"point"};
    Json::Value::Members keys;
    JSONCPP_STRING error;
    Json::CharReaderBuilder builder;
    const std::unique_ptr<Json::CharReader> reader(builder.newCharReader());

    result = reader->parse(json_string.c_str(), json_string.c_str() + json_string.size(), &root, &error);
    if (!result)
    {
        return result;
    }
    keys = root.getMemberNames();
    for (auto &key : keys)
    {
        if (key == space)
        {
            output_value_str[key] = root[key].asString();
        }
        else if (key == point)
        {
            const Json::Value data = root[key];
            for (unsigned int i{0}; i < data.size(); i++)
            {
                output_value_num[key][i] = data[i].asDouble();
            }
        }
        else 
        {
            return result;
        }
    }

    return true;
}

bool GetArrayFromJson(std::string json_string, std::vector<double> &output_value)
{
    bool result{false};
    Json::Value root;
    Json::Value::Members keys;
    JSONCPP_STRING error;
    Json::CharReaderBuilder builder;
    const std::unique_ptr<Json::CharReader> reader(builder.newCharReader());

    result = reader->parse(json_string.c_str(), json_string.c_str() + json_string.size(), &root, &error);
    if (!result)
    {
        return result;
    }
    keys = root.getMemberNames();
    const Json::Value data = root[keys.front()];
    for (unsigned int i{0}; i < data.size(); i++)
    {
        output_value.push_back(data[i].asDouble());
    }
    return true;
}

bool GetArrayFromJson(std::string json_string, std::vector<int> &output_value)
{
    bool result{false};
    Json::Value root;
    Json::Value::Members keys;
    JSONCPP_STRING error;
    Json::CharReaderBuilder builder;
    const std::unique_ptr<Json::CharReader> reader(builder.newCharReader());

    result = reader->parse(json_string.c_str(), json_string.c_str() + json_string.size(), &root, &error);
    if (!result)
    {
        return result;
    }
    keys = root.getMemberNames();
    const Json::Value data = root[keys.front()];
    for (unsigned int i{0}; i < data.size(); i++)
    {
        output_value.push_back(data[i].asInt());
    }
    return true;   
}

bool GetProgramCommandsFromJson(std::string json_string, std::vector<std::pair<std::string, std::vector<double>>> &output_value)
{
    bool result{false};
    std::vector<double> position_array;
    std::pair<std::string, std::vector<double>> single_command;
    Json::Value root;
    Json::Value data;
    Json::Value::Members keys;
    Json::Value::Members data_keys;
    JSONCPP_STRING error;
    Json::CharReaderBuilder builder;
    const std::unique_ptr<Json::CharReader> reader(builder.newCharReader());

    result = reader->parse(json_string.c_str(), json_string.c_str() + json_string.size(), &root, &error);
    if (!result)
    {
        return result;
    }
    keys = root.getMemberNames();
    for (unsigned int i{0}; i < root[keys.front()].size(); i++)
    {
        position_array.clear();
        data = root[keys.front()][i];
        data_keys = data.getMemberNames();
        for (unsigned int j{0}; j < data[data_keys.front()].size(); j++)
        {
            position_array.push_back(data[data_keys.front()][j].asDouble());
        }
        single_command.first = data_keys.front();
        single_command.second = position_array;
        output_value.push_back(single_command);
    }
    return true;
}

}  // namespace zjyt 
