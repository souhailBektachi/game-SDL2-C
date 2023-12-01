#include "Character.h"


void character(float x,float y,SDL_Texture* texture,Character* character,int speed){
    entity(x,y,texture,&character->character,32,32);
    character->coll=0;
    character->speed=speed;
    character->textures[0]=texture;
}
int CgetSpeed(Character* character){
    return character->speed;
}




void movecharacter(float p_x,float p_y,Character* character,Map* p_Map,char pos){
    
    int tempx=entity_getx(&character->character);
    int tempy=entity_gety(&character->character);

    
    
     if (entity_getx(&character->character)+p_x < 0 || entity_getx(&character->character)+p_x > SCREEN_WIDTH - entity_getCFrame(&character->character).w ) {
        p_x = 0;
    } 
     if (entity_gety(&character->character)+p_y < 0 || entity_gety(&character->character)+p_y > SCREEN_HEIGHT - entity_getCFrame(&character->character).h-16 ) {
        p_y = 0;
    }
    entity_setx(&character->character,entity_getx(&character->character)+ p_x);
    entity_sety(&character->character,entity_gety(&character->character)+p_y);
        
        int coll=character_collision(character,p_Map,pos);
        if(coll){
            entity_setx(&character->character,tempx);
            entity_sety(&character->character,tempy);
        }
    }
    

void addTextuers(SDL_Texture* textures[],Character* character,int size){
    for (int i = 0; i < size; i++)
    {
        character->textures[i]=textures[i];

    }

}

int character_collision(const Character* p_a,const Map* p_b,char pos){
   int C_x=p_a->character.destFrame.x+8;
   int C_y=p_a->character.destFrame.y+8;
//    int mapTileS=p_b->mapTiles[0][0].Tile.destFrame.h;
   
   
    
    
   
            if('W'==p_b->mapTiles[C_y/16][C_x/16].type){
                
           return 1;}else{
            return 0;
           }
       
   
}


