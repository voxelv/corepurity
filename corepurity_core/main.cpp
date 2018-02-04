#include "src/graphics/window.h"
#include "src/math/math.h"

int main() 
{
    using namespace corepurity_core;
    using namespace graphics;
    using namespace math;

    Window window("CorePurity", 960, 540);
    glClearColor(0.2f, 0.3f, 0.8f, 0.0f);

    vec2 vector(1.0f, 2.0f);
    
    std::cout << vector << std::endl;

    GLuint vao;
    glGenVertexArrays(1, &vao);
    glBindVertexArray(vao);

    while (!window.closed())
    {
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
#if 1
        glBegin(GL_QUADS);
        glVertex2f(-0.5f, -0.5f);
        glVertex2f(-0.5f,  0.5f);
        glVertex2f( 0.5f,  0.5f);
        glVertex2f( 0.5f, -0.5f);
        glEnd();
#else
        glDrawArrays(GL_ARRAY_BUFFER, 0, 0);
#endif
        window.update();
    }

    return 0;
}

