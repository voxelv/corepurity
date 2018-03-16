#ifndef COREPURITY_CORE_GRAPHICS_VERTEXARRAY_H
#define COREPURITY_CORE_GRAPHICS_VERTEXARRAY_H

#include <vector>
#include <GL/glew.h>

#include "buffer.h"

namespace corepurity_core { namespace graphics {

    class VertexArray
    {
    private:
        GLuint m_ArrayID;
        std::vector<Buffer*> m_Buffers;

    public:
        VertexArray();
        ~VertexArray();

        void addBuffer(Buffer *buffer, GLuint index);
        void bind() const;
        void unbind() const;
    };

} }

#endif//COREPURITY_CORE_GRAPHICS_VERTEXARRAY_H
