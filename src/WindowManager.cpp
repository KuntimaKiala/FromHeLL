#include "WindowManager.hpp"


WindowManager::WindowManager(int width=500, int height=500, const std::string& windowName ="FromHeLL")
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