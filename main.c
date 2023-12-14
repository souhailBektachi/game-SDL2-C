#include <stdio.h>
#include <stdlib.h>
#include "game.h"
int WinMain()
{

    // Uint32 framesStart;
    // int frameTime;
    // double deltaTime = 0.0f;
    game game;
    gameInit(&game, "game with no name");

    while (game.isRunning)
    {
        // framesStart = SDL_GetTicks();
        handleEvents(&game);
        renderGame(&game);
    }
    cleanGame(&game);
    SDL_Quit();
    return 0;
}
