#pragma once
#include "entity.h"
#include "csts.h"
#include <stdio.h>
typedef struct 
{
    Entity character;
    int speed;

}Character;

void movecharacter(int p_x,int p_y,Character* character);

void character(float x,float y,SDL_Texture* texture,Character* character,int speed);
int CgetSpeed(Character* character);