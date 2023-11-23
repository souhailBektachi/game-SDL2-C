#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <stdio.h>
#include "renderwindow.h"
#include "entity.h"
#include <stdlib.h>

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
    SDL_Texture* dirtTexture=loadtexture("assets/gfx/dirt.png",&window);
    SDL_Texture* cloudTexture=loadtexture("assets/gfx/cloud.png",&window);

    Entity platform0;
    Entity platform1;
    Entity platform2;
    int valx[4];
    int valy[4];
    for (int i = 0; i < 4; i++)
    {
        
            int randomy = (rand() % (200 - 10 + 1)) + 10;
            int randomx = (rand() % (790 - 10 + 1)) + 10;
            valx[i]=randomx;
            valy[i]=randomy;

    }
    

    
    entity(0,300,grassTexture,&platform0);
    entity(0,332,dirtTexture,&platform1);
    entity(100,100,cloudTexture,&platform2);

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
            for(int i=0;i<4;i++){
                SDL_Rect temp;
                        entity_setx(&platform2,valx[i]);
            entity_sety(&platform2,valy[i]);


            temp.h=63;
            temp.w=107;
            entity_setCFrame(&platform2,temp);

            render(&platform2,&window);
            }
            for (int x = 0; x < 32*27; x+=32)
            {

                entity_setx(&platform0,x);
                render(&platform0,&window);

                
                
                
            }
               
            
                
            
            
            for(int y=332;y<480;y+=32){
                
                entity_sety(&platform1,y);
            for (int x = 0; x < 32*27; x+=32)
            {

                entity_setx(&platform1,x);
                render(&platform1,&window);
                
                
                
            }
               }
            
                
            
            
            
            display(&window);
        

    }
    cleanUp(&window);
    SDL_Quit();
    return 0;
}
