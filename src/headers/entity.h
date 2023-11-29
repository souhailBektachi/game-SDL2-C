#pragma once
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <stdio.h>
#include <stdbool.h>
typedef struct 
{
    SDL_Rect destFrame;
    float x,y;
    SDL_Rect currentFrame;
    SDL_Texture* texture;

}Entity;

void entity(float x,float y,SDL_Texture* texture,Entity* entity,float h,float w);
float entity_getx(Entity* entity);
float entity_gety(Entity* entity);
SDL_Texture* entity_getTex(Entity* entity);
SDL_Rect entity_getCFrame(Entity* entity);
void entity_setx(Entity* entity,float x);
void entity_sety(Entity* entity,float y);
void entity_setTex(Entity* entity,SDL_Texture* tex);
void entity_setCFrame(Entity* entity,float h,float w,float x,float y);
int entity_collision(const Entity* p_a,const Entity* p_b);
