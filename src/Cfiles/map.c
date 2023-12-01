#include "map.h"
    
void map(SDL_Texture* maptex, const char* csvFile,Map* map,mapwall* walls){
    map->csvFile=csvFile;
    map->maptex=maptex;
    
    entity(0,0,map->maptex,&map->theMap,16,16);
    map->rendered=0;
    
    map->walls[0].keys=walls->keys;
    map->walls[0].type=walls->type;
    
    
}

void createMap(Map* map){
    
   
    parseCsv(map->csvFile,map->mapKeys);
   
    
    
    

    
    



    
    
   
    

}

void renderMap(Map* map,RenderW* window,int textureHW){
    int key,x,y;
    
    int k=0;
    for (int i = 0; i < 30*16; i+=16)
    {
        for(int j=0;j<30*16;j+=16){
            key=map->mapKeys[k];
            k++;
            x=(key%textureHW)*16;
            y=(key/textureHW)*16;
       
            
            if(!map->rendered){
            entity(j,i,map->maptex,&map->mapTiles[i/16][j/16].Tile,16,16);
            

            
            entity_setCFrame(&map->mapTiles[i/16][j/16].Tile,16,16,x,y);
            
            }
                 for (int w = 0; w <1; w++)
            {
                if(map->walls->keys[w]==key){
                    map->mapTiles[i/16][j/16].type=map->walls[0].type;
                    break;
                }else{
                     map->mapTiles[i/16][j/16].type='N';
                     continue;
                }
            
            }

            
            render(&map->mapTiles[i/16][j/16].Tile,window,0);

    }
    
}   
    set_rendered(map,1);
    

}
int get_rendered(Map* map){
    return map->rendered;
}
void set_rendered(Map* map,int x){
    map->rendered=x;
}
