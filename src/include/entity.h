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
