#pragma once
#include "entity.h"
#include "csts.h"
#include "csv.h"
#include "renderwindow.h"


typedef struct {
    int rendered;
    Entity theMap;
    Entity mapTiles[30][30];
    SDL_Texture* maptex;
    int mapKeys[1000];
    const char* csvFile;
    


}Map;

void map(SDL_Texture* maptex,const char* csvFile,Map* map);
void createMap(Map* map);
void renderMap(Map* map,RenderW* window,int textureHW);
int get_rendered(Map* map);
void set_rendered(Map* map,int x);