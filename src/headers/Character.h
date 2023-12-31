#pragma once
#include "entity.h"
#include "csts.h"
#include <stdio.h>
#include "map.h"
#include "string.h"
#include "vector2d.h"
// #include "math.h"

typedef struct
{
    Entity character;
    int speed;
    SDL_Texture *textures[5];
    int coll;
    int isDead;
    int isAccelerated;
    double angle;
    int cycle;
} Character;

void character(float x, float y, SDL_Texture *textures[], Character *character, int speed);
void movecharacter(double angle, Character *character, Map *p_Map);
int CgetSpeed(Character *character);
void addTextures(SDL_Texture *textures[], Character *character, int size);
void character_collision(Character *p_a, Map *p_b);
void copy_character(Character *p_a, Character *p_b);
void Kill_Character(Character *p_a);
int isDead(Character *p_a);
void reveive_character(Character *p_a);

int isAccelerated(Character *p_a);
void C_accelerate(Character *p_a);
void cleanCharacter(Character *p_a);
void Character_animate(Character *p_a);