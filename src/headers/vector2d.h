#pragma once
#include <stdlib.h>
#include <math.h>

typedef struct vector2d 
{
    float x,y;
}vector2d;


void vector(vector2d* v,int x,int y);
vector2d addVec(vector2d p_a,vector2d p_b);
vector2d SubVec(vector2d p_a,vector2d p_b);
vector2d multiplyBy(vector2d p_a,float x);
vector2d rotateVector(vector2d* p_a,int angle);