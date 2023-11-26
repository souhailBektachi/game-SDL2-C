#include "entity.h"

void entity(float x,float y,SDL_Texture* texture,Entity* entity)
{
 
    entity->destFrame.x=x;
    entity->destFrame.y=y;
    entity->destFrame.h=16;
    entity->destFrame.w=16;
    
    entity->currentFrame.x=0;
    entity->currentFrame.y=0;
    entity->currentFrame.h=32;
    entity->currentFrame.w=32;
    
    
    entity->texture=texture;


}
float entity_getx(Entity* entity){
    return entity->destFrame.x;
}
float entity_gety(Entity* entity){
    return entity->destFrame.y;
}
SDL_Texture* entity_getTex(Entity* entity){
    return entity->texture;
}
SDL_Rect entity_getCFrame(Entity* entity){
    return entity->currentFrame;
}
void entity_setx(Entity* entity,float x){
    entity->destFrame.x=x;
    
}
void entity_sety(Entity* entity,float y){
    entity->destFrame.y=y;
   
}
void entity_setTex(Entity* entity,SDL_Texture* tex){
    entity->texture=tex;
}
void entity_setCFrame(Entity* entity,float h,float w,float x,float y){
    entity->currentFrame.h=h;
    entity->currentFrame.w=w;
    entity->currentFrame.x=x;
    entity->currentFrame.y=y;

}
int entity_collision(const Entity* p_a,const Entity* p_b){
//     printf("Player: (%d, %d, %d, %d)\n", p_a->destFrame.x, p_a->destFrame.y, p_a->destFrame.w, p_a->destFrame.h);
// printf("Obstacle: (%d, %d, %d, %d)\n", p_b->destFrame.x, p_b->destFrame.y, p_b->destFrame.w, p_b->destFrame.h);
   
    return SDL_HasIntersection(&p_a->destFrame,&p_b->destFrame);
    
}