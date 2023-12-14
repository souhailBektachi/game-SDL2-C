#pragma once
#include "entity.h"
#include "csts.h"
#include <stdio.h>
#include "map.h"
#include "vector2d.h"
#include "Character.h"

typedef struct
{
    Entity ball;
    int speed;
    SDL_Texture *ball_texture;
    double angle;

} Ball;
void ball(float x, float y, SDL_Texture *ball_texture, Ball *ball, int speed, double angle);
void moveBall(Ball *ball, Map *p_map, Character *character);
int BgetSpeed(Ball *ball);
int ball_collision(Ball *ball, Map *p_b);
void ball_setSpeed(Ball *ball, int speed);
int ball_getSpeed(Ball *ball);
void Set_BallAngle(Ball *ball, double angle);
double Get_BallAngle(Ball *ball);
void ballCharacter_collision(Ball *ball, Character *character);
void cleanBall(Ball *ball);