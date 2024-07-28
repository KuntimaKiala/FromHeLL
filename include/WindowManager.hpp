#ifndef WINDOWMANAGER_HPP
#define WINDOWMANAGER_HPP

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include "VertexObjects.hpp"
#include "utils.hpp"

class WindowManager
{

    
public:
    
    explicit WindowManager(int width, int height, const std::string& windowName);
    virtual ~WindowManager();
    void     createWindow();

private:
    void Init();
    static void framebuffersize_callback(GLFWwindow*, int, int) ;
    void Setup();
private :
    int m_iWidth;
    int m_iHeight;
    GLFWwindow* m_pWindow;
    const std::string m_sWindowName;
    int m_iOpenGLVersion;

};

#endif
