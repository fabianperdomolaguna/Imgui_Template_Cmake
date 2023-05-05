#pragma once

#include <string>

struct ImageData
{
    uint8_t* data = nullptr;
    int width;
    int height;
    int channels;
    uint32_t format;
};

ImageData ReadImage(std::string file_path);