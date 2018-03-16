#ifndef COREPURITY_CORE_GRAPHICS_SIMPLE2DRENDERER_H
#define COREPURITY_CORE_GRAPHICS_SIMPLE2DRENDERER_H

#include <deque>
#include "renderer2d.h"

namespace corepurity_core { namespace graphics {

    class Simple2DRenderer : public Renderer2D
    {
    private:
        std::deque<const Renderable2D*> m_RenderQueue;

    public:
        void submit(const Renderable2D *renderable) override;
        void flush() override;
    };

} }

#endif//COREPURITY_CORE_GRAPHICS_SIMPLE2DRENDERER_H