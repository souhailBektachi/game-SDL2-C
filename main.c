#include <stdio.h>
#include <stdlib.h>
#include "game.h"
int WinMain()
{

    Uint32 framesStart;
    int frameTime;
    double deltaTime = 0.0f;
    Uint32 lastFrameTime = SDL_GetTicks();
    game game;
    gameInit(&game, "game with no name");

    while (game.isRunning)
    {
        framesStart = SDL_GetTicks();

        handleEvents(&game);
        update(&game, deltaTime);
        renderGame(&game);
        frameTime = SDL_GetTicks() - framesStart;
        Uint32 currentFrameTime = SDL_GetTicks();
        deltaTime = (currentFrameTime - lastFrameTime) / 1000.0f;
        lastFrameTime = currentFrameTime;

        if (framdelay > frameTime)
        {
            printf("%f:%f\n", getDelta_time(&game.player.character), deltaTime);
            SDL_Delay(framdelay - frameTime);
        }
    }
    cleanGame(&game);
    SDL_Quit();
    return 0;
}
