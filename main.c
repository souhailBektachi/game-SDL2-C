#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <stdio.h>
#include "renderwindow.h"
#include "entity.h"
#include <stdlib.h>
#include "csts.h"
#include "Character.h"
#include "map.h"

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
    RenderWindow("Game with no name",SCREEN_WIDTH,SCREEN_HEIGHT,&window);
    SDL_Texture* playerTextures[4]={loadtexture("assets/gfx/run.png",&window),loadtexture("assets/gfx/runUP.png",&window),loadtexture("assets/gfx/rundown.png",&window)};
    SDL_Texture* playerTexture=loadtexture("assets/gfx/run.png",&window);
    SDL_Texture* playerTextureUP=loadtexture("assets/gfx/runUP.png",&window);
    SDL_Texture* playerTextureDown=loadtexture("assets/gfx/rundown.png",&window);
    SDL_Texture* playerTextureUPLR=loadtexture("assets/gfx/runUpToLeft.png",&window);
    SDL_Texture* playerTextureDownLR=loadtexture("assets/gfx/runDownLeft.png",&window);
    Character player;


    Map themap[2];
    const char* mapAssets[2]={"assets/maps/firstlevel.csv","assets/maps/secondlevel.csv"};
    SDL_Texture* maptexture[2]={loadtexture("assets/gfx/map.png",&window),loadtexture("assets/gfx/dungeontileset-extended.png",&window)};

    int mapTextureHW[2]={23,64};

    for (int i = 0; i < 2; i++)
    {
        map(maptexture[i],mapAssets[i],&themap[i]);
        createMap(&themap[i]);
    }
    

    character(200,271,playerTexture,&player,10);
    
    
    int gameRunning=1;
    int flip=0;
    int mapindex=0;
    SDL_Event event;   
    while(gameRunning){
        while (SDL_PollEvent(&event))
        {
            const Uint8 *keyboardState = SDL_GetKeyboardState(NULL);
            
            if(event.type==SDL_QUIT){
                gameRunning =0;
            }
            if(keyboardState[SDL_SCANCODE_UP] && keyboardState[SDL_SCANCODE_RIGHT]){
                entity_setTex(&player.character,playerTextureUPLR);
                flip=1;
                movecharacter(CgetSpeed(&player),-CgetSpeed(&player),&player);
                
            }else if(keyboardState[SDL_SCANCODE_UP] && keyboardState[SDL_SCANCODE_LEFT]){
                entity_setTex(&player.character,playerTextureUPLR);
                flip=0;
                movecharacter(-CgetSpeed(&player),-CgetSpeed(&player),&player);
                
            }else if(keyboardState[SDL_SCANCODE_DOWN] && keyboardState[SDL_SCANCODE_RIGHT]){
                entity_setTex(&player.character,playerTextureDownLR);
                flip=1;
                movecharacter(CgetSpeed(&player),CgetSpeed(&player),&player);
                
            }else if(keyboardState[SDL_SCANCODE_DOWN] && keyboardState[SDL_SCANCODE_LEFT]){
                entity_setTex(&player.character,playerTextureDownLR);
                flip=0;
                movecharacter(-CgetSpeed(&player),CgetSpeed(&player),&player);
                
            }else if(keyboardState[SDL_SCANCODE_DOWN]){
                entity_setTex(&player.character,playerTextureDown);
                movecharacter(0,CgetSpeed(&player),&player);
                
                
            }else if(keyboardState[SDL_SCANCODE_UP]){
                entity_setTex(&player.character,playerTextureUP);
                movecharacter(0,-CgetSpeed(&player),&player);
                
                
            }else if(keyboardState[SDL_SCANCODE_LEFT]){
                entity_setTex(&player.character,playerTexture);
                movecharacter(-CgetSpeed(&player),0,&player);
                flip=1;
                
                
            }else if(keyboardState[SDL_SCANCODE_RIGHT]){
                entity_setTex(&player.character,playerTexture);
                movecharacter(CgetSpeed(&player),0,&player);
                flip=0;
                
                
            }
            

            if(event.type==SDL_KEYDOWN){
                
                switch (event.key.keysym.sym)
                {
                case SDLK_v:
                    

                    mapindex=mapindex==0?1:0;

                default:
                    break;
                }
            }
            
        }
            clear(&window);
            renderMap(&themap[mapindex],&window,mapTextureHW[mapindex]);
            render(&player.character,&window,flip);
                
            
            
            
            display(&window);
        

    }
    cleanUp(&window);
    SDL_Quit();
    return 0;
}
