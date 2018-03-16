#ifndef COREPURITY_CORE_GRAPHICS_RENDERER2D_H
#define COREPURITY_CORE_GRAPHICS_RENDERER2D_H

#include <GL/glew.h>
#include "../math/math.h"
#include "renderable2d.h"

namespace corepurity_core { namespace graphics {

    class Renderer2D
    {
    public:
        virtual void submit(const Renderable2D *renderable) = 0;
        virtual void flush() = 0;
    };

} }

#endif//COREPURITY_CORE_GRAPHICS_RENDERER2D_H