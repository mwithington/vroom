#pragma once
#include <map>
#include <string>

class ConfigService {
  private:
    std::map<std::string, std::string> config;

  public:
    void loadConfig(std::string path);
    std::string getValue(std::string key);
    std::string getValue(std::string key, std::string defaultValue);

    int getIntValue(std::string key);
    int getIntValue(std::string key, int defaultValue);

    std::string setValue(std::string key, std::string value);
}
