#pragma once
#include "entity.h"
#include "csts.h"
#include <stdio.h>
#include "map.h"
#include "vector2d.h"

typedef struct{
    Entity ball;
    int speed;
    SDL_Texture* ball_texture;
    
}Ball;
void ball(float x,float y,SDL_Texture* ball_texture,Ball* ball,int speed);
void moveBall(Ball* ball,Map* p_map);
int BgetSpeed(Ball* ball);
void ball_collision(Ball* ball,Map* p_b);