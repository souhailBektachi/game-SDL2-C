#include "map.h"

void map(SDL_Texture* maptex, const char* csvFile,Map* map){
    map->csvFile=csvFile;
    map->maptex=maptex;
    
    entity(0,0,map->maptex,&map->theMap);
    
}

void createMap(Map* map){
    
   
    parseCsv(map->csvFile,map->mapKeys);
   
    
    
    

    
    



    
    
   
    

}
void renderMap(Map* map,RenderW* window){
    int key,x,y;
    int k=0;
    for (int i = 0; i < 30*16; i+=16)
    {
        entity_sety(&map->theMap,i);
        for(int j=0;j<30*16;j+=16){
            entity_setx(&map->theMap,j);
            key=map->mapKeys[k];
            k++;
            x=(key%23)*16;
            y=(key/23)*16;
            entity_setCFrame(&map->theMap,16,16,x,y);
            render(&map->theMap,window,0);
        }
    }
    
}
