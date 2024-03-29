#include <cstdint>

#include "glad/glad.h"

#include "texture.h"

Texture::Texture(uint8_t* data, int width, int height, uint32_t format)
{
    m_width = width;
    m_height = height;
    m_format = format;

    glGenTextures(1, &render_texture);
	glBindTexture(GL_TEXTURE_2D, render_texture);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexImage2D(GL_TEXTURE_2D, 0, m_format, m_width, m_height, 0, m_format, GL_UNSIGNED_BYTE, data);
}

Texture::~Texture()
{
    glDeleteTextures(1, &render_texture);
}

uint32_t Texture::get_texture()
{
    return render_texture;
}