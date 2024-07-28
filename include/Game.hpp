#ifndef GAME_HPP
#define GAME_HPP
#include "WindowManager.hpp"
#include <iostream>
#include <string>

class Game : public WindowManager
{

public:
  
     Game(int width=500, int height=500, const std::string& windowName ="FromHeLL");
    ~Game();
    void Render();
};



#endif