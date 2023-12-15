#include "map.h"

void map(SDL_Texture *maptex, const char *csvFile, Map *map, const char *wallFile, float h, float w)
{
    map->csvFile = csvFile;
    map->maptex = maptex;
    map->wallFile = wallFile;
    entity(0, 0, map->maptex, &map->theMap, 16, 16);
    map->rendered = 0;
    map->srcTilesSize.h = h;
    map->srcTilesSize.w = w;
    for (int i = 0; i < HASH_SIZE; ++i)
    {
        map->walls.table[i] = NULL;
    }
}

void createMap(Map *map)
{

    parseCsv(map->csvFile, map->mapKeys);
    Wallscsv(map->wallFile, map);
}

void renderMap(Map *map, RenderW *window, int textureHW)
{
    int key, x, y;
    int srcSize = (int)get_srcTilesSize(map);
    int tilesize = (int)get_mapTilesSize(map);
    int mapsize = SCREEN_HEIGHT / tilesize;
    int k = 0;
    for (int i = 0; i < mapsize * tilesize; i += tilesize)
    {
        for (int j = 0; j < mapsize * tilesize; j += tilesize)
        {
            key = map->mapKeys[k];
            k++;
            x = (key % textureHW) * srcSize;
            y = (key / textureHW) * srcSize;
            if (!map->rendered)
            {

                entity(j, i, map->maptex, &map->mapTiles[i / tilesize][j / tilesize].Tile, tilesize, tilesize);

                entity_setCFrame(&map->mapTiles[i / tilesize][j / tilesize].Tile, srcSize, srcSize, x, y);
                set_destFrame(&map->mapTiles[i / tilesize][j / tilesize].Tile, tilesize, tilesize);
                setKey(&map->mapTiles[i / tilesize][j / tilesize], key);
            }

            render(&map->mapTiles[i / tilesize][j / tilesize].Tile, window, 0);
        }
    }
    set_rendered(map, 1);
}
int get_rendered(Map *map)
{
    return map->rendered;
}
void set_rendered(Map *map, int x)
{
    map->rendered = x;
}
void setKey(mapE *Emap, int key)
{
    Emap->key = key;
}
void Set_mapTilesSize(Map *map, float size)
{

    map->mapTilesSize.h = map->mapTilesSize.w = size;
}
float get_mapTilesSize(Map *map)
{
    return map->mapTilesSize.w;
}
float get_srcTilesSize(Map *map)
{
    return map->srcTilesSize.w;
}
void cleanMap(Map *map)
{
    SDL_DestroyTexture(map->maptex);
    free(map);
}
