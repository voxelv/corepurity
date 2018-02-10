#ifndef COREPURITY_CORE_GRAPHICS_SHADER_H
#define COREPURITY_CORE_GRAPHICS_SHADER_H

#include <iostream>
#include <vector>

#include "../utl/file_utl.h"
#include "../math/math.h"
#include <GL/glew.h>

namespace corepurity_core { namespace graphics {

    class Shader
    {
    private:
        GLuint m_ShaderID;
        const char *m_VertPath;
        const char *m_FragPath;
    public:
        Shader(const char* vertPath, const char* fragPath);
        ~Shader();

        void setUniform1f(const GLchar *name, float value);
        void setUniform1i(const GLchar *name, int value);

        void setUniform2f(const GLchar *name, const math::vec2& vector);
        void setUniform3f(const GLchar *name, const math::vec3& vector);
        void setUniform4f(const GLchar *name, const math::vec4& vector);

        void setUniformMat4(const GLchar *name, const math::mat4& matrix);


        void enable() const;
        void disable() const;
    private:
        GLuint load();
        GLint getUniformLocation(const GLchar *name);
    };

} }

#endif//COREPURITY_CORE_GRAPHICS_SHADER_H