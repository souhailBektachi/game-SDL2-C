#pragma once
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

typedef struct 
{
    float x,y;
    SDL_Rect currentFrame;
    SDL_Texture* texture;

}Entity;

void entity(float x,float y,SDL_Texture* texture,Entity* entity);
float entity_getx(Entity* entity);
float entity_gety(Entity* entity);
SDL_Texture* entity_getTex(Entity* entity);
SDL_Rect entity_getCFrame(Entity* entity);
void entity_setx(Entity* entity,int x);
void entity_sety(Entity* entity,int y);
void entity_setTex(Entity* entity,SDL_Texture* tex);
void entity_setCFrame(Entity* entity,SDL_Rect CFrame);
