#include "Character.h"


void character(float x,float y,SDL_Texture* texture,Character* character,int speed){
    entity(x,y,texture,&character->character,32,32);
    character->coll=0;
    character->speed=speed;
    character->textures[0]=texture;
    character->isDead=0;
}
int CgetSpeed(Character* character){
    return character->speed;
}




void movecharacter(double angle,Character* character,Map* p_Map){
    
    vector2d temppos=entity_getpos(&character->character);
    Character tempC;
    copy_character(&tempC,character);
    int p_x =character->speed*cos(angle);
    int p_y =character->speed* sin(angle);
    entity_setpos(&tempC.character,temppos.x+p_x,temppos.y+p_y);
    
   
    

    character_collision(&tempC ,p_Map);
    entity_setpos(&character->character,tempC.character.pos.x,tempC.character.pos.y);
        
       
    }
    

void addTextuers(SDL_Texture* textures[],Character* character,int size){
    for (int i = 0; i < size; i++)
    {
        character->textures[i]=textures[i];

    }

}

void character_collision(Character* p_a, Map* p_b){
   int C_x=p_a->character.pos.x+p_a->character.currentFrame.w/2;
   int C_y=p_a->character.pos.y+p_a->character.currentFrame.h/2;
   mapE Tile = p_b->mapTiles[C_y/16][C_x/16];
   char type =getType(&p_b->walls,Tile.key>0?Tile.key:0);
   vector2d tempvect=p_a->character.pos;
//    int mapTileS=p_b->mapTiles[0][0].Tile.destFrame.h;
   
    
            if(type !='\0'){
                
                tempvect=entity_collision(p_a->character.currentFrame,Tile.Tile.currentFrame,p_a->character.pos,Tile.Tile.pos,type);
                vector(&tempvect,tempvect.x,tempvect.y);
                entity_setpos(&p_a->character,tempvect.x,tempvect.y);
               
         }
       
   
}


void copy_character(Character* p_a,Character* p_b){
    character(p_b->character.pos.x,p_b->character.pos.y,p_b->textures[0],p_a,p_b->speed);
}

int isDead(Character* p_a){
    return p_a->isDead;
}
void Kill_Character(Character* p_a){
    if(!p_a->isDead){
    p_a->isDead=1;}
    
}
void reveive_character(Character* p_a){
     if(p_a->isDead){
    p_a->isDead=0;}
   
}