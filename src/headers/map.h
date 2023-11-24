#pragma once
#include "entity.h"
#include "csts.h"



typedef struct {
    SDL_Texture* map;
    const char* csvFile;
    int map[14400];



}Map;

void map(SDL_Texture* map,const char* csvFile);
void rendermap(Map* map);
