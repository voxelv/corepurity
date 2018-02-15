#ifndef COREPURITY_CORE_GRAPHICS_INDEXBUFFER_H
#define COREPURITY_CORE_GRAPHICS_INDEXBUFFER_H

#include <GL/glew.h>

namespace corepurity_core { namespace graphics {

    class IndexBuffer
    {
    private:
        GLuint m_BufferID;
        GLuint m_Count;
    public:
        IndexBuffer(GLushort *data, GLsizei count);

        void bind() const;
        void unbind() const;
        GLuint getCount() const { return m_Count; }
    };

} }

#endif//COREPURITY_CORE_GRAPHICS_INDEXBUFFER_H
