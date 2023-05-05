#pragma once

#include <memory>

#include "layer.h"
#include "texture.h"

class SimpleRender : public Layer
{
    std::unique_ptr<Texture> image_texture;
    std::unique_ptr<Texture> mpl_texture;

    void OnAttach() override;
    void OnRender() override;
};