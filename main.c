#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <stdio.h>
#include "renderwindow.h"
#include "entity.h"
int WinMain()
{

    if (SDL_Init(SDL_INIT_VIDEO)>0)
    {
        printf("SDL INIT HAS FAILED %s",SDL_GetError());
    }
    
   if ((IMG_Init(IMG_INIT_PNG) & IMG_INIT_PNG) != IMG_INIT_PNG) {
    fprintf(stderr, "Unable to initialize SDL_image: %s\n", IMG_GetError());
    return 1;
}


    RenderW window;
    RenderWindow("test",854,480,&window);
    
    SDL_Texture* grassTexture=loadtexture("assets/gfx/ground_grass_1.png",&window);
    Entity platform0;
    entity(100,100,grassTexture,&platform0);


    int gameRunning=1;
    SDL_Event event;   
    while(gameRunning){
        while (SDL_PollEvent(&event))
        {
            if(event.type==SDL_QUIT){
                gameRunning =0;
            }
            
        }
            clear(&window);
            
                render(&platform0,&window);
            
            
            
            display(&window);
        

    }
    cleanUp(&window);
    SDL_Quit();
    return 0;
}
