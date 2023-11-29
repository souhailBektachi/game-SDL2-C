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




void movecharacter(int p_x,int p_y,Character* character){
    

    
    
    
     if (entity_getx(&character->character)+p_x < 0 || entity_getx(&character->character)+p_x > SCREEN_WIDTH - entity_getCFrame(&character->character).w) {
        p_x = 0;
    } 
     if (entity_gety(&character->character)+p_y < 0 || entity_gety(&character->character)+p_y > SCREEN_HEIGHT - entity_getCFrame(&character->character).h-16) {
        p_y = 0;
    }
    entity_setx(&character->character,entity_getx(&character->character)+p_x);
    entity_sety(&character->character,entity_gety(&character->character)+p_y);

}
void addTextuers(SDL_Texture* textures[],Character* character,int size){
    for (int i = 0; i < size; i++)
    {
        character->textures[i]=textures[i];

    }

}

int character_collision(const Character* p_a,const Map* p_b){
   int C_x=p_a->character.destFrame.x;
   int C_y=p_a->character.destFrame.y;
   int mapTileS=p_b->mapTiles[0][0].Tile.destFrame.h;
   
   
    
    
   
            if('W'==p_b->mapTiles[C_y/16][C_x/16].type){
                
           return entity_collision(&p_a->character,&p_b->mapTiles[C_y/16][C_x/16].Tile);}else{
            return 0;
           }
       
   
}