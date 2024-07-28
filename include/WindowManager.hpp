#ifndef WINDOWMANAGER_HPP
#define WINDOWMANAGER_HPP

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include <string>

class WindowManager
{

    
public:
    WindowManager() = delete;
    explicit WindowManager(int width=500, int height=500, const std::string& windowName ="FromHeLL");
    ~WindowManager();

private:
    void Init();
    static void framebuffersize_callback(GLFWwindow*, int, int);
private :
    int m_iWidth;
    int m_iHeight;
    GLFWwindow* m_pWindow;
    const std::string m_sWindowName;
    int m_iOpenGLVersion;

};

#endif
