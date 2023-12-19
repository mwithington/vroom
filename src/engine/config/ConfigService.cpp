#include "./ConfigService.h"
#include <utility>

ConfigService::ConfigService() {}

// TODO(Tom): vector at will throw oob if key doesn't exist, we should add try/catch

void ConfigService::loadConfig(std::string path) {
  this->config = std::map<std::string, std::string>();

  std::ifstream fileHandle;
  fileHandle.open(path, std::ios::in);

  if (fileHandle.is_open()) {
    std::string currLine;
    while(std::getline(fileHandle, currLine)) {
      std::cout << currLine << std::endl;
      std::size_t found = currLine.find("=");
      std::string key = currLine.substr(0, found);
      std::string value = currLine.substr(found + 1, (int)currLine.size());

      config.insert(std::pair<std::string, std::string>(key, value));
    }

    fileHandle.close();

    std::cout << "Finished loading config..." << std::endl;
  } else {
    std::cout << "Failed to open config file..." << std::endl;
  }
}

std::string ConfigService::getValue(std::string key) {
  return this->config.at(key);
}

std::string ConfigService::getValue(std::string key, std::string defaultValue) {
  std::string valStr = this->config.at(key);

  if (valStr.empty()) {
    return defaultValue;
  }

  return valStr;
}

int ConfigService::getIntValue(std::string key) {
  std::string valStr = this->config.at(key);

  if (valStr.empty()) {
    return NULL;
  }

  return std::stoi(valStr);
}

int ConfigService::getIntValue(std::string key, int defaultValue) {
  std::string valStr = this->config.at(key);

  if (valStr.empty()) {
    return defaultValue;
  }

  return std::stoi(valStr);
}

float ConfigService::getFloatValue(std::string key) {
  std::cout << "get float key: " << key << std::endl;
  std::string valStr = this->config.at(key);
  std::cout << "valStr : " << valStr << std::endl;


  if (valStr.empty()) {

    return NULL;
  }

  return std::stof(valStr);

}

float ConfigService::getFloatValue(std::string key, float defaultValue) {
  std::string valStr = this->config.at(key);

  if (valStr.empty()) {
    return defaultValue;
  }

  return std::stof(valStr);
}

void ConfigService::setValue(std::string key, std::string value) {
  this->config.at(key) = value; // Test this actually updates
}

void ConfigService::setIntValue(std::string key, int value) {
  this->config.at(key) = std::to_string(value);
}

void ConfigService::setFloatValue(std::string key, float value) {
  this->config.at(key) = std::to_string(value);
}
