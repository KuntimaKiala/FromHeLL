#include <iostream>
#include "Game.hpp"

int main(int argc, char *argv[])
{
    Game *FromHeLL = new Game();

    FromHeLL->Render();
    delete FromHeLL;
    
    return 0;
}