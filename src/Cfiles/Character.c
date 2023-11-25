#include "Character.h"


void character(float x,float y,SDL_Texture* texture,Character* character,int speed){
    entity(x,y,texture,&character->character);

    character->speed=speed;
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
