#include "entity.h"

void entity(float x,float y,SDL_Texture* texture,Entity* entity,float h,float w)
{
 
    entity->destFrame.x=x;
    entity->destFrame.y=y;
    entity->destFrame.h=h;
    entity->destFrame.w=w;
    
    entity->currentFrame.x=0;
    entity->currentFrame.y=0;
    entity->currentFrame.h=h;
    entity->currentFrame.w=w;
    
    
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
    SDL_Rect Rect1={p_a->destFrame.x,p_a->destFrame.y,p_a->destFrame.w,p_a->destFrame.h};
    SDL_Rect Rect2={p_b->destFrame.x,p_b->destFrame.y,p_b->destFrame.w,p_b->destFrame.h};
    bool RightEdge=(Rect1.x+Rect1.w)>=(Rect2.x);
    bool LeftEdge=(Rect1.x)<=(Rect2.x+Rect2.w);
    bool TopEdge=(Rect1.y+Rect1.h)>=(Rect2.y);
    bool BottomEdge=Rect1.y<=(Rect2.y+Rect2.h);
    
    return (LeftEdge && TopEdge )||  (TopEdge && RightEdge) || (LeftEdge && BottomEdge) || (RightEdge && BottomEdge) || LeftEdge || TopEdge || RightEdge || BottomEdge?1:0;
    
    
   
    
}