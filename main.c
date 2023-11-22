#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <stdio.h>
#include "renderwindow.h"
int WinMain()
{
    if (SDL_Init(SDL_INIT_VIDEO)>0)
    {
        printf("SDL INIT HAS FAILED %s",SDL_GetError());
    }
    
    if(!(IMG_Init(IMG_INIT_PNG))){
        printf("Img init has failed %s",IMG_GetError());


    }
    RenderW window;
    RenderWindow("test",960,540,window);
    // SDL_Texture* grassTexture=loadtexture("assets/gfx/ground_grass_1.png",window);



    int gameRunning=1;
    SDL_Event event;
    while(gameRunning){
        while (SDL_PollEvent(&event))
        {
            if(event.type==SDL_QUIT){
                gameRunning =0;
            }
            
        }
            // clear(window);
            // render(grassTexture,window);
            // display(window);
        

    }
    cleanUp(window);
    SDL_Quit();
    return 0;
}
