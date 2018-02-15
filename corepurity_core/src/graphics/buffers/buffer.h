#ifndef COREPURITY_CORE_GRAPHICS_BUFFER_H
#define COREPURITY_CORE_GRAPHICS_BUFFER_H

#include <GL/glew.h>

namespace corepurity_core { namespace graphics {

    class Buffer
    {
    private:
        GLuint m_BufferID;
        GLuint m_ComponentCount; // vec?
    public:
        Buffer(GLfloat *data, GLsizei count, GLuint componentCount);

        void bind() const;
        void unbind() const;
        GLuint getComponentCount() const { return m_ComponentCount; }
    };

} }

#endif//COREPURITY_CORE_GRAPHICS_BUFFER_H
