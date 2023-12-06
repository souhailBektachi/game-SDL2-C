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




void movecharacter(float p_x,float p_y,Character* character,Map* p_Map){
    
    vector2d temppos=entity_getpos(&character->character);

    
    
     if (temppos.x+p_x < 0 || temppos.x+p_x > SCREEN_WIDTH - entity_getCFrame(&character->character).w ) {
        p_x = 0;
    } 
     if (temppos.y+p_y < 0 || temppos.y+p_y > SCREEN_HEIGHT - entity_getCFrame(&character->character).h-16 ) {
        p_y = 0;
    }
    
   
    entity_setpos(&character->character,temppos.x+ p_x,temppos.y+p_y);
    character_collision(character ,p_Map);
        
       
    }
    

void addTextuers(SDL_Texture* textures[],Character* character,int size){
    for (int i = 0; i < size; i++)
    {
        character->textures[i]=textures[i];

    }

}

int character_collision(const Character* p_a,const Map* p_b){
   int C_x=p_a->character.pos.x+16;
   int C_y=p_a->character.pos.y+16;
   mapE Tile = p_b->mapTiles[C_y/16][C_x/16];
   
   char type =getType(&p_b->walls,Tile.key>0?Tile.key:0);
   vector2d tempvect=p_a->character.pos;
//    int mapTileS=p_b->mapTiles[0][0].Tile.destFrame.h;
   
    
    
            if(type !='\0'){
                
                tempvect=entity_collision(p_a->character.currentFrame,Tile.Tile.currentFrame,p_a->character.pos,Tile.Tile.pos,type);
                vector(&tempvect,tempvect.x,tempvect.y);
                entity_setpos(&p_a->character,tempvect.x,tempvect.y);
                return 1;
         }else{
            return 0;
           }
       
   
}


