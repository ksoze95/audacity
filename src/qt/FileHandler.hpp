#pragma once

#include <map>
#include <string>
#include "AudioFile.hpp"

class FileHandler
{
public:
    FileHandler();
    ~FileHandler();

    bool containsSound(const std::string& filename);
    AudioFile & getSound(const std::string& filename);
private:
    std::map<std::string, AudioFile> sounds;
};
