#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <stdio.h>
#include "renderwindow.h"
#include "entity.h"
#include <stdlib.h>
#include "csts.h"
#include "Character.h"

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
    SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY,"2");


    RenderW window;
    RenderWindow("test",SCREEN_WIDTH,SCREEN_HEIGHT,&window);
    
    SDL_Texture* grassTexture=loadtexture("assets/gfx/ground_grass_1.png",&window);
    SDL_Texture* dirtTexture=loadtexture("assets/gfx/dirt.png",&window);
    SDL_Texture* playerTexture=loadtexture("assets/gfx/run.png",&window);
    SDL_Texture* maptexture=loadtexture("assets/gfx/map.png",&window);
    Entity platform0;
    Entity platform1;
    Character player;
    Entity map;


    
    entity(0,300,grassTexture,&platform0);
    entity(0,332,dirtTexture,&platform1);
    entity(10,10,maptexture,&map);
    SDL_Rect temp;
    temp.h=64;
    temp.w=64;
    temp.x=(48%23)*16;
    temp.y=(48/23)*16;
    entity_setCFrame(&map,temp);
    character(200,271,playerTexture,&player,10);
    
    
    int gameRunning=1;
    int flip=0;
    SDL_Event event;   
    while(gameRunning){
        while (SDL_PollEvent(&event))
        {
            if(event.type==SDL_QUIT){
                gameRunning =0;
            }
            if(event.type==SDL_KEYDOWN){
                
                switch (event.key.keysym.sym)
                {
                case SDLK_RIGHT:
                    flip=0;
                    movecharacter(CgetSpeed(&player),0,&player);
                    break;
                case SDLK_LEFT:
                    flip=1;
                    movecharacter(-CgetSpeed(&player),0,&player);
                    break;
                default:
                    break;
                }
            }
            
        }
            clear(&window);
            render(&map,&window,0);
            render(&player.character,&window,flip);
            for (int x = 0; x < 32*15; x+=32)
            {

                entity_setx(&platform0,x);
                render(&platform0,&window,0);

                
                
                
            }
               
            
                
            
            
            for(int y=332;y<480;y+=32){
                
                entity_sety(&platform1,y);
            for (int x = 0; x < 32*27; x+=32)
            {

                entity_setx(&platform1,x);
                render(&platform1,&window,0);
                
                
                
            }
               }
            
                
            
            
            
            display(&window);
        

    }
    cleanUp(&window);
    SDL_Quit();
    return 0;
}
