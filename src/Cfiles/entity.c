#include "entity.h"

void entity(float x,float y,SDL_Texture* texture,Entity* entity)
{
    
    entity->x=x;
    entity->y=y;
    entity->currentFrame.x=0;
    entity->currentFrame.y=0;
    entity->currentFrame.h=32;
    entity->currentFrame.w=32;

    
    entity->texture=texture;


}
float entity_getx(Entity* entity){
    return entity->x;
}
float entity_gety(Entity* entity){
    return entity->y;
}
SDL_Texture* entity_getTex(Entity* entity){
    return entity->texture;
}
SDL_Rect entity_getCFrame(Entity* entity){
    return entity->currentFrame;
}
void entity_setx(Entity* entity,float x){
    entity->x=x;
}
void entity_sety(Entity* entity,float y){
    entity->y=y;
}
void entity_setTex(Entity* entity,SDL_Texture* tex){
    entity->texture=tex;
}
void entity_setCFrame(Entity* entity,SDL_Rect CFrame){
    entity->currentFrame.h=CFrame.h;
    entity->currentFrame.w=CFrame.w;
    entity->currentFrame.x=CFrame.x;
    entity->currentFrame.y=CFrame.y;

}