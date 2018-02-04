#include "window.h"
#include <iostream>

namespace corepurity_core { namespace graphics
{
    void window_resize(GLFWwindow *window, int width, int height);
    void key_callback(GLFWwindow *window, int key, int scancode, int action, int mods);
    void mouse_button_callback(GLFWwindow *window, int button, int action, int mods);
    void cursor_position_callback(GLFWwindow *window, double xpos, double ypos);

    Window::Window(const char *title, int width, int height)
    {
        m_Title = title;
        m_Width = width;
        m_Height = height;

        if (!init())
        {
            glfwTerminate();
        }

        for (int i = 0; i < MAX_KEYS; i++)
        {
            m_Keys[i] = false;
        }

        for (int i = 0; i < MAX_BUTTONS; i++)
        {
            m_MouseButtons[i] = false;
        }
    }

    Window::~Window()
    {
        glfwTerminate();
    }

    bool Window::init()
    {
        if (!glfwInit())
        {
            std::cout << "Failed to initialize GLFW!" << std::endl;
            return false;
        }

        m_Window = glfwCreateWindow(m_Width, m_Height, m_Title, NULL, NULL);
        if (!m_Window)
        {
            std::cout << "Failed to create GLFW window!" << std::endl;
            return false;
        }
        glfwMakeContextCurrent(m_Window);
        glfwSetWindowUserPointer(m_Window, this);
        glfwSetWindowSizeCallback(m_Window, window_resize);
        glfwSetKeyCallback(m_Window, key_callback);
        glfwSetMouseButtonCallback(m_Window, mouse_button_callback);
        glfwSetCursorPosCallback(m_Window, cursor_position_callback);

        /*
        GLEW initialization must happen after context creation.
        */
        if (glewInit() != GLEW_OK)
        {
            std::cout << "Failed to initialize GLEW!" << std::endl;
            return false;
        }

        std::cout << "OpenGL " << glGetString(GL_VERSION) << std::endl;

        return true;
    }

    bool Window::isKeyPressed(unsigned int keycode) const
    {
        if (keycode >= MAX_KEYS)
        {
            std::cout << "Invalid keycode!" << std::endl;
        }
        else
        {
            return m_Keys[keycode];
        }
        return false;
    }
    
    bool Window::isMouseButtonPressed(unsigned int button) const
    {
        if (button >= MAX_BUTTONS)
        {
            std::cout << "Invalid Button!" << std::endl;
        }
        else
        {
            return m_MouseButtons[button];
        }
        return false;
    }

    void Window::getMousePosition(double& x, double& y) const
    {
        x = mx;
        y = my;
    }

    void Window::clear() const
    {
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    }

    void Window::update()
    {
        glfwPollEvents();
        glfwSwapBuffers(m_Window);
    }

    bool Window::closed() const
    {
        return glfwWindowShouldClose(m_Window) == GL_TRUE;
    }

    void window_resize(GLFWwindow *window, int width, int height)
    {
        glViewport(0, 0, width, height);
    }

    void key_callback(GLFWwindow * window, int key, int scancode, int action, int mods)
    {
        Window *win = (Window*)glfwGetWindowUserPointer(window);
        switch (action)
        {
        case GLFW_PRESS:
            win->m_Keys[key] = true;
            break;
        case GLFW_RELEASE:
            win->m_Keys[key] = false;
            break;
        default:
            break;
        }
    }

    void mouse_button_callback(GLFWwindow * window, int button, int action, int mods)
    {
        Window *win = (Window*)glfwGetWindowUserPointer(window);
        switch (action)
        {
        case GLFW_PRESS:
            win->m_MouseButtons[button] = true;
            break;
        case GLFW_RELEASE:
            win->m_MouseButtons[button] = false;
            break;
        default:
            break;

        }

    }

    void cursor_position_callback(GLFWwindow *window, double xpos, double ypos)
    {
        Window *win = (Window*)glfwGetWindowUserPointer(window);
        win->mx = xpos;
        win->my = ypos;
    }

} }
