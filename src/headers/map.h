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
    SDL_Rect mapTilesSize;
    SDL_Rect srcTilesSize;

} Map;

void map(SDL_Texture *maptex, const char *csvFile, Map *map, const char *wallFile, float h, float w);
void createMap(Map *map);
void renderMap(Map *map, RenderW *window, int textureHW);
int get_rendered(Map *map);
void set_rendered(Map *map, int x);
void setKey(mapE *Emap, int key);
void cleanMap(Map *map);
void Set_mapTilesSize(Map *map, float size);
float get_mapTilesSize(Map *map);
float get_srcTilesSize(Map *map);