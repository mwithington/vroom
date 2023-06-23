#pragma once
#include <map>
#include <string>
#include <iostream>
#include <fstream>

class ConfigService {
  private:
    std::map<std::string, std::string> config;

  public:
    ConfigService();
    void loadConfig(std::string path);

    std::string getValue(std::string key);
    std::string getValue(std::string key, std::string defaultValue);
    int getIntValue(std::string key);
    int getIntValue(std::string key, int defaultValue);
    float getFloatValue(std::string key);
    float getFloatValue(std::string key, float defaultValue);

    void setValue(std::string key, std::string value);
    void setIntValue(std::string key, int value);
    void setFloatValue(std::string key, float value);
};
