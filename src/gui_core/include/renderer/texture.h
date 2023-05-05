#pragma once

#include <stdint.h>

class Texture 
{
    uint32_t image_texture;

public:
    uint32_t m_width = 0, m_height = 0;
    uint32_t m_format = 0;

    Texture(uint8_t* data, int width, int height, uint32_t format);
    ~Texture();
    
    uint32_t get_texture();
};