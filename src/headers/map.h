#pragma once
typedef struct Map Map;

#include "entity.h"
#include "csts.h"
#include "csv.h"
#include "renderwindow.h"
#include "hashmap.h"
typedef struct
{
    Entity Tile;
    int key;

} mapE;
typedef struct Map
{
    int rendered;
    Entity theMap;
    mapE mapTiles[30][30];

    SDL_Texture *maptex;
    int mapKeys[1000];
    const char *csvFile;
    const char *wallFile;
    HashMap walls;
    int wallsSize;
    int mapTextureHW[2];

} Map;

void map(SDL_Texture *maptex, const char *csvFile, Map *map, const char *wallFile);
void createMap(Map *map);
void renderMap(Map *map, RenderW *window, int textureHW);
int get_rendered(Map *map);
void set_rendered(Map *map, int x);
void setKey(mapE *Emap, int key);
void cleanMap(Map *map);