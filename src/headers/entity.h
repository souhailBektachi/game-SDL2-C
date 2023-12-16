#pragma once
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <stdio.h>
#include <stdbool.h>
#include <vector2d.h>
#include "csts.h"

// #include "math.h"
typedef struct
{

    SDL_Rect currentFrame;
    SDL_Rect destFrame;
    vector2d pos;
    SDL_Texture *texture;
    float delta_time;
    int isflipped;

} Entity;

void entity(float x, float y, SDL_Texture *texture, Entity *entity, float h, float w);
vector2d entity_getpos(Entity *entity);
SDL_Texture *entity_getTex(Entity *entity);
SDL_Rect entity_getCFrame(Entity *entity);
void entity_setpos(Entity *entity, float x, float y);
void entity_setTex(Entity *entity, SDL_Texture *tex);
void entity_setCFrame(Entity *entity, float h, float w, float x, float y);
vector2d entity_collision(const SDL_Rect p_a, SDL_Rect p_b, vector2d p_aPos, vector2d p_bPos, char type);
int entityToEntity_collision(Entity *p_a, Entity *p_b);
void setDelta_time(Entity *entity, float deltaTime);
float getDelta_time(Entity *entity);
void cleanEntity(Entity *entity);
void set_destFrame(Entity *entity, float h, float w);
SDL_Rect get_destFrame(Entity *entity);