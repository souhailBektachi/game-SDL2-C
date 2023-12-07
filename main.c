#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <stdio.h>
#include "renderwindow.h"
#include "entity.h"
#include <stdlib.h>
#include "csts.h"
#include "Character.h"
#include "map.h"
#include "ball.h"
int WinMain()
{
                

    const int FPS=60;
    const int framdelay =1000/FPS;
    Uint32 framesStart;
    int frameTime;

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
    // SDL_Texture* playerTextures[4]={loadtexture("assets/gfx/run.png",&window),loadtexture("assets/gfx/runUP.png",&window),loadtexture("assets/gfx/rundown.png",&window)};
    SDL_Texture* playerTexture=loadtexture("assets/gfx/run.png",&window);
    SDL_Texture* playerTextureUP=loadtexture("assets/gfx/runUP.png",&window);
    SDL_Texture* playerTextureDown=loadtexture("assets/gfx/rundown.png",&window);
    SDL_Texture* playerTextureUPLR=loadtexture("assets/gfx/runUpToLeft.png",&window);
    SDL_Texture* playerTextureDownLR=loadtexture("assets/gfx/runDownLeft.png",&window);
    SDL_Texture* Balltexture=loadtexture("assets/gfx/ball.png",&window);
    Character player;
    Character Player2;
    character(200,200,playerTexture,&Player2,10);

    Map themap[2];
    const char* mapAssets[2]={"assets/maps/firstlevel.csv","assets/maps/secondlevel.csv"};
    SDL_Texture* maptexture[2]={loadtexture("assets/gfx/map.png",&window),loadtexture("assets/gfx/dungeontileset-extended.png",&window)};
    const char* mapWalls[2]={"assets/maps/secondlevelwalls.csv","assets/maps/secondlevelwalls.csv"};
    int mapTextureHW[2]={23,64};



    for (int i = 0; i < 2; i++)
    {
        map(maptexture[i],mapAssets[i],&themap[i],mapWalls[i]);
        createMap(&themap[i]);
    }
    
    
    character(200,271,playerTexture,&player,10);
    Ball theball;
    ball(200,200,Balltexture,&theball,3);
    
    int gameRunning=1;
    int flip=0;
    int mapindex=1;
    
    SDL_Event event;   
    while(gameRunning){
        while (SDL_PollEvent(&event))
        {
            framesStart=SDL_GetTicks();
            const Uint8 *keyboardState = SDL_GetKeyboardState(NULL);

            

            if(event.type==SDL_QUIT){
                gameRunning =0;
            }

            if(keyboardState[SDL_SCANCODE_UP] && keyboardState[SDL_SCANCODE_RIGHT]){
                entity_setTex(&player.character,playerTextureUPLR);
                flip=1;
                movecharacter(-M_PI/4,&player,&themap[mapindex]);
                
            }else if(keyboardState[SDL_SCANCODE_UP] && keyboardState[SDL_SCANCODE_LEFT]){
                entity_setTex(&player.character,playerTextureUPLR);
                flip=0;
                movecharacter(-(3*M_PI)/4,&player,&themap[mapindex]);
                
            }else if(keyboardState[SDL_SCANCODE_DOWN] && keyboardState[SDL_SCANCODE_RIGHT]){
                entity_setTex(&player.character,playerTextureDownLR);
                flip=1;
                movecharacter(M_PI/4,&player,&themap[mapindex]);
                
                
            }else if(keyboardState[SDL_SCANCODE_DOWN] && keyboardState[SDL_SCANCODE_LEFT]){
                entity_setTex(&player.character,playerTextureDownLR);
                flip=0;
                movecharacter((3*M_PI)/4,&player,&themap[mapindex]);
                
            }else if(keyboardState[SDL_SCANCODE_DOWN]){
                entity_setTex(&player.character,playerTextureDown);
                movecharacter(M_PI / 2.0,&player,&themap[mapindex]);
                
                
            }else if(keyboardState[SDL_SCANCODE_UP]){
                entity_setTex(&player.character,playerTextureUP);
                movecharacter(-M_PI / 2.0,&player,&themap[mapindex]);
                
                
            
            }else if(keyboardState[SDL_SCANCODE_LEFT]){
                entity_setTex(&player.character,playerTexture);
                movecharacter(M_PI ,&player,&themap[mapindex]);
                flip=1;
                

                
                
            }else if(keyboardState[SDL_SCANCODE_RIGHT] ){
                entity_setTex(&player.character,playerTexture);
                movecharacter(0,&player,&themap[mapindex]);
                flip=0;
                
            
                
            }

            if(event.type==SDL_KEYDOWN){
                
                switch (event.key.keysym.sym)
                {
                case SDLK_v:
                    

                    set_rendered(&themap[mapindex],0);
                    mapindex=mapindex==0?1:0;

                    break;
 


                default:
                    break;
                }
            }
            
        }
        

            clear(&window);
            renderMap(&themap[mapindex],&window,mapTextureHW[mapindex]);
            render(&player.character,&window,flip);
            entity_setpos(&Player2.character,150,entity_getpos(&Player2.character).y);
            // render(&Player2.character,&window,0);
            render(&theball.ball,&window,0);
            moveBall(&theball,&themap[mapindex]);
            
            display(&window);
            // printmap(&themap[mapindex]);
            frameTime=SDL_GetTicks()-framesStart;
            if(framdelay>frameTime){
            SDL_Delay(framdelay-frameTime);

           }
            
        

    }
    cleanUp(&window);
    SDL_Quit();
    return 0;
}
