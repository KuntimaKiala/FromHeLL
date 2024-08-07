#include "Game.hpp"

Game::Game(int width, int height, const std::string& windowName)
: WindowManager(width, height, windowName)
{
    std::cout << "Game Launch" <<std::endl;
}

Game::~Game()
{
    Service::Utility::Print("GAME ENDED");
}

void Game::Render()
{       
        std::cout << "Rendering" <<std::endl;
        createWindow();
}
