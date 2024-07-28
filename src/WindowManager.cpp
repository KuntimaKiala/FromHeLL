#include "WindowManager.hpp"


WindowManager::WindowManager(int width, int height, const std::string& windowName)
: m_iWidth(width)
, m_iHeight(height)
, m_pWindow(NULL)
, m_sWindowName(windowName)
, m_iOpenGLVersion(3)
{
   float vertices[] = {
        -0.5f, -0.5f, -0.5f,  0.0f, 0.0f,
         0.5f, -0.5f, -0.5f,  1.0f, 0.0f,
         0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
         0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
        -0.5f,  0.5f, -0.5f,  0.0f, 1.0f,
        -0.5f, -0.5f, -0.5f,  0.0f, 0.0f,

        -0.5f, -0.5f,  0.5f,  0.0f, 0.0f,
         0.5f, -0.5f,  0.5f,  1.0f, 0.0f,
         0.5f,  0.5f,  0.5f,  1.0f, 1.0f,
         0.5f,  0.5f,  0.5f,  1.0f, 1.0f,
        -0.5f,  0.5f,  0.5f,  0.0f, 1.0f,
        -0.5f, -0.5f,  0.5f,  0.0f, 0.0f,

        -0.5f,  0.5f,  0.5f,  1.0f, 0.0f,
        -0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
        -0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
        -0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
        -0.5f, -0.5f,  0.5f,  0.0f, 0.0f,
        -0.5f,  0.5f,  0.5f,  1.0f, 0.0f,

         0.5f,  0.5f,  0.5f,  1.0f, 0.0f,
         0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
         0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
         0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
         0.5f, -0.5f,  0.5f,  0.0f, 0.0f,
         0.5f,  0.5f,  0.5f,  1.0f, 0.0f,

        -0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
         0.5f, -0.5f, -0.5f,  1.0f, 1.0f,
         0.5f, -0.5f,  0.5f,  1.0f, 0.0f,
         0.5f, -0.5f,  0.5f,  1.0f, 0.0f,
        -0.5f, -0.5f,  0.5f,  0.0f, 0.0f,
        -0.5f, -0.5f, -0.5f,  0.0f, 1.0f,

        -0.5f,  0.5f, -0.5f,  0.0f, 1.0f,
         0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
         0.5f,  0.5f,  0.5f,  1.0f, 0.0f,
         0.5f,  0.5f,  0.5f,  1.0f, 0.0f,
        -0.5f,  0.5f,  0.5f,  0.0f, 0.0f,
        -0.5f,  0.5f, -0.5f,  0.0f, 1.0f
    };
}

WindowManager::~WindowManager()
{

}

void WindowManager::Init()
{
    if (m_iOpenGLVersion < 3)
    {
        std::cout << "You are Using Immediate Mode" << std::endl;
    }
    
    if( !glfwInit())
    {
        std::cout << "OpenGL FrameWork Failed To Initialize" << std::endl;
    }
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, m_iOpenGLVersion);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, m_iOpenGLVersion);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
}

void WindowManager::framebuffersize_callback(GLFWwindow* window, int width, int height) 
{
    glViewport(0,0, width, height);
}

void WindowManager::createWindow()
{
    Init();
    m_pWindow = glfwCreateWindow(m_iWidth, m_iHeight, m_sWindowName.c_str(), NULL, NULL);

    if (!m_pWindow)
    {
        std::cout << "Window Creation Failed" << std::endl;
    }
    
    glfwMakeContextCurrent(m_pWindow);
    
 
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        std::cout << "GLAD Failed" << std::endl;
    }
    glfwSetFramebufferSizeCallback(m_pWindow, framebuffersize_callback);

    while (!glfwWindowShouldClose(m_pWindow))
    {
        glClearColor(0.23f, 0.1f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);
        
        glfwPollEvents();
        glfwSwapBuffers(m_pWindow);
    }
    
    glfwTerminate();
    
}