#pragma once
#include "entity.h"
#include "csts.h"
#include "csv.h"
#include "renderwindow.h"


typedef struct {
    Entity theMap;
    SDL_Texture* maptex;
    int mapKeys[1000];
    const char* csvFile;
    



}Map;

void map(SDL_Texture* maptex,const char* csvFile,Map* map);
void createMap(Map* map);
void renderMap(Map* map,RenderW* window);