#include "WindowManager.hpp"


WindowManager::WindowManager(int width, int height, const std::string& windowName)
: m_iWidth(width)
, m_iHeight(height)
, m_pWindow(NULL)
, m_sWindowName(windowName)
, m_iOpenGLVersion(3)
{
   
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
    
}