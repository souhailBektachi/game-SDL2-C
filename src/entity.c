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